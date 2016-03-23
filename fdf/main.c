/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:48:19 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/28 12:48:21 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage : ./fdf source_file\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	parsing(fd);
	return (0);
}