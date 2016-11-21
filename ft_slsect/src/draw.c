/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:04:04 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 14:05:07 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	write_line(LP *curr, INF *infos, int x, int y)
{
	ft_goto(x + 2, y);
	if (curr->select)
		ft_tputs("mr", 1);
	ft_putstr_color_fd(" ", curr->select ? GREEN : RESET, infos->fd, 1);
	if (curr->on)
		ft_tputs("us", 1);
	ft_putstr_color_fd(curr->value, curr->select || curr->on ?
	GREEN : RESET, infos->fd, 1);
	ft_tputs("ue", 1);
	ft_putstr_times(" ", infos->col_size - (ft_strlen(curr->value) + 5),
	curr->select ? GREEN : RESET, infos->fd);
	ft_tputs("me", 1);
}

void		draw(INF *infos, LP *curr)
{
	int x;
	int y;

	x = 3;
	y = 0;
	ft_tputs("ho", 1);
	ft_tputs("cd", 1);
	while (curr->page != infos->curr_page)
		curr = curr->next;
	while (curr && curr->page == infos->curr_page)
	{
		while (curr && y < infos->nb_lines && curr->page == infos->curr_page)
		{
			write_line(curr, infos, x, 1 + y++);
			curr = curr->next;
		}
		y = 0;
		x += infos->col_size;
	}
	ft_goto(0, infos->height);
	render_bar(get_infos());
}
