/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 07:52:31 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/23 13:57:40 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int			check_stock(char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		return (ft_strlen(*line) > 0 ? 1 : 0);
	}
	return (0);
}

static int			check_read(char *buffer, char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (ft_strlen(*line) > 0 ? 1 : 0);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	char			*buffer;
	int				ret;

	if (stock)
		if (check_stock(&stock, line))
			return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (check_read(buffer, &stock, line))
			return (1);
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	if (ret < 0)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}