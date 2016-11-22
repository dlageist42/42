/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:03 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:02:12 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static BOOL	is_arrow(int key)
{
	return (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT);
}

static void	handle_keys(t_select *select, int kc)
{
	if (kc == K_ESC)
	{
		if (select->search.i)
			search_reset(&select->search);
		else
			select_quit(select, FALSE);
	}
	else if (kc == K_ENTER)
	{
		if (select->search.i)
			search_find(&select->search);
		else
			select_quit(select, TRUE);
	}
	else if (kc == K_SPACE)
		select_toggle(select);
	else if (kc == K_DEL)
		select_del(select);
	else if (is_arrow(kc))
		select_move(select, kc);
	else if (kc == K_BACKSPACE)
		search_remove(&select->search);
	else if (kc > 32 && kc < 127)
		search_add(&select->search, (char)kc);
}

void		handle_inputs(t_select *select)
{
	char	buff[4];
	int		key;

	while (42)
	{
		ft_bzero(buff, 4);
		read(0, buff, 4);
		if ((key = KEY(buff)) == K_CTRLD)
			select_quit(select, FALSE);
		else if (select->active)
			handle_keys(select, key);
	}
}
