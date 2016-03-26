/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:57:10 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/24 14:57:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_args(char **av)
{
	int		i;

	i = 1;
	while (i > 0)
	{
		if (av[i + 1][0] != '-')
			i = 0;
		else if (av[i + 1] == NULL)
			i = -1;

	}
}

int			check_arg(char **av)
{
	if (av[1][0] != '-' && av[2][0] == '-')
	{
		ft_putstr("ls : ");
		ft_putstr(av[2]);
		ft_putstr(": No such file or directory\n");
	}
	if (av[1] == '-')
		get_args(av);
	return (0);		
}