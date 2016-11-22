/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:11:59 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:32:13 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	window_too_small(t_select *select)
{
	static char str[] = "WINDOW TOO SMALL !";
	int			x;

	select->active = FALSE;
	x = (select->size.ws_col / 2) - (ft_strlen(str) / 2);
	term_go_home();
	term_clear_down();
	term_write(CRED);
	term_goto_relative(x, select->size.ws_row / 2);
	term_write(str);
}

void		select_render(t_select *select)
{
	t_item *current;

	if (select->size.ws_col < select->items_width + 2
	|| select->size.ws_col < 25)
		return (window_too_small(select));
	select->active = TRUE;
	current = select->items;
	term_clear();
	term_show_cursor(FALSE);
	while (42)
	{
		if (current->page > select->page)
			break ;
		if (current->page == select->page)
			select_render_item(select, current);
		if (current->next == select->items)
			break ;
		current = current->next;
	}
	select_render_bar(select);
	search_render(&select->search);
}
