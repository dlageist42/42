/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:03:26 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 14:06:13 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	write_input(int c)
{
	INF *infos;

	infos = get_infos();
	write(infos->fd, &c, 1);
	return (0);
}

void		ft_tputs(char *cap, int nb)
{
	tputs(tgetstr(cap, NULL), nb, write_input);
}

void		ft_putstr_color_fd(char *s, char *col, int fd, int res)
{
	ft_putstr_fd(col, fd);
	ft_putstr_fd(s, fd);
	if (res)
		ft_putstr_fd(RESET, fd);
}

void		ft_putstr_times(char *str, int nb, char *col, int fd)
{
	int i;

	i = 0;
	while (i <= nb)
	{
		ft_putstr_color_fd(str, col, fd, 1);
		i++;
	}
}

void		ft_goto(int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, write_input);
}
