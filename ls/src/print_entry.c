/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:03:58 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/16 12:05:38 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

void	print_link(char *path)
{
	static char buffer[200] = {0};

	if (readlink(path, buffer, 200) != -1)
	{
		ft_putstr(" -> ");
		ft_putstr(buffer);
	}
	ft_strclr(buffer);
}

void	print_entry(t_elst *entry)
{
	static char *colors[] = COLORS;
	char		*color;

	color = colors[entry->type];
	if (!color)
		return (ft_putendl(entry->name));
	write(1, colors[entry->type], 5);
	ft_putstr(entry->name);
	write(1, CDEF, 5);
	if (g_long_display && entry->type == ELNK)
		print_link(entry->path);
	ft_putchar('\n');
}
