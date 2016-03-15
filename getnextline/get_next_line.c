/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 08:34:42 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/15 09:25:15 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static int			check_stock(char **stock, char **line)
{
	char *ptr;

	if ((ptr = ft_strchr(*stock, '\n')))
	{
		*ptr = '\0';
		*line = ft_strdup(*stock);
		*stock += ft_strlen(*stock) + 1;
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	if (stock == NULL)
		while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
		{
			buffer[ret] = '\0';
			stock = ft_strjoin(stock, buffer);
		}
	if (stock == NULL || ret < 0)
		return (-1);
	else if (check_stock(&stock, line))
		return (1);
	else
	{
		*line = ft_strdup(stock);
		stock += ft_strlen(stock) + 1;
		return (1);
	}
}

int			main(int ac, char **av)
{
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
