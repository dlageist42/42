/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:43:55 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:44:39 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		load_params(char **argv)
{
	int	i;
	LP	**first;

	i = 1;
	first = lst_get_first();
	while (argv[i])
		lst_push(first, argv[i++]);
}

void		print_params(LP *first)
{
	if (first)
	{
		while (first)
		{
			if (first->select)
			{
				ft_putstr(first->value);
				ft_putstr(" ");
			}
			first = first->next;
		}
		ft_putendl("");
	}
}

static int	line_per_page(void)
{
	INF *infos;
	int i;

	i = 1;
	infos = get_infos();
	if (infos->nb_params < infos->nb_lines)
		return (infos->nb_params);
	while ((i + 1) * infos->col_size < infos->width)
		i++;
	return (i * infos->nb_lines);
}

void		set_params(LP *first, INF *infos)
{
	int nb_line_per_page;
	int page;
	int y;
	int i;

	i = 0;
	y = 0;
	page = 1;
	nb_line_per_page = line_per_page();
	while (first)
	{
		if (i >= nb_line_per_page)
		{
			page++;
			i = 0;
		}
		if (y == infos->nb_lines)
			y = 0;
		first->page = page;
		first->y = y++;
		first = first->next;
		i++;
	}
	(get_infos())->nb_pages = page;
}
