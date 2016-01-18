/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:02:39 by dlageist          #+#    #+#             */
/*   Updated: 2016/01/18 16:46:02 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

#define BUFF_SIZE 1000

char			lastLigne(char *str, int stock)
{

}
int				get_next_line(int const fd, char **line)
{
	static	int	stock = 0;
	int i;
	char *str;

	i = 0;
	if (stock != 0)
		free(*ligne);
	if (!(str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	read(fd, str, BUFF_SIZE);
	while (str[i] != '\n')
	{
		i++;
		if (str[i] == '\0')
		{
			lastLigne(str, stock);
			return (0);
	}
	*line = ft_strdup(str, stock, i);
	stock = i++;
	return (1);
}
