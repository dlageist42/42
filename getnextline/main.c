/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 07:52:31 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/21 16:36:52 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int ret;
	int fd;
	char *line;

	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	ret = get_next_line(fd, &line);
	printf("line = %s, ret = %d\n", line, ret);
	return (0);
}