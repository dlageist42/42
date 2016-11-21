/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:54:00 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:54:25 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	config(LP **curr, INF **infos)
{
	*curr = *(lst_get_first());
	(*curr)->on = 1;
	*infos = get_infos();
	(*infos)->curr_page = 1;
	if ((*infos)->valid_size > 0)
		draw(*infos, *(lst_get_first()));
}

void		start_select(void)
{
	char	buf[4];
	INF		*infos;
	LP		*curr;

	config(&curr, &infos);
	while (curr)
	{
		ft_bzero(buf, 4);
		read(0, buf, 4);
		if (infos->valid_size < 1)
			continue;
		input_handler(lst_get_first(), infos, &curr, buf);
		if (!curr)
			exit_prog();
		fill_infos();
		draw(infos, *(lst_get_first()));
	}
}
