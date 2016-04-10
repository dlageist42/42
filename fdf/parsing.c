/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:48:19 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/28 12:48:21 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			parsing(int fd)
{
	char	*line;
	char	***map;
	int		i;
	int		ret;
	int		x;

	i = 0;
	ret = 0;
	x = 0;
	while((ret = get_next_line(fd, &line)) > 0)
	{
		map[i] = ft_strsplit(line, ' ');
		i++;
	}
	if (ret == -1)
		return (1);
	return (0);
}