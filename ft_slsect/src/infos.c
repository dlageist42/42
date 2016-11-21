/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:05:13 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 15:05:55 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

INF				*get_infos(void)
{
	static INF infos;

	return (&infos);
}

static int		check_size(INF *infos)
{
	if (infos->col_size > infos->width || infos->width < 65 ||
		infos->height < 4)
	{
		ft_tputs("ho", 1);
		ft_tputs("cd", 1);
		ft_putstr_times(" ", (infos->width / 2) - 10, BLINK_MODE, 2);
		ft_putstr_color_fd("Windows too small :/", RED, 2, 1);
		ft_putstr_color_fd(" ", RESET_MODE, 2, 1);
		infos->valid_size = -1;
		return (0);
	}
	infos->valid_size = 1;
	return (1);
}

void			fill_infos(void)
{
	struct winsize	ws;
	INF				*infos;

	infos = get_infos();
	if (infos->fd == 0)
		infos->fd = open(ttyname(0), O_WRONLY);
	if (!infos->load_cap)
		enable_env();
	ioctl(infos->fd, TIOCGWINSZ, &ws);
	infos->nb_lines = ws.ws_row - 3;
	infos->nb_params = lst_get_size(lst_get_first());
	infos->col_size = lst_get_size_line(lst_get_first()) + 5;
	infos->height = ws.ws_row;
	infos->width = ws.ws_col;
	check_size(infos);
	set_params(*(lst_get_first()), infos);
}
