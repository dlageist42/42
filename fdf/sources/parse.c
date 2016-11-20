/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpernes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:44:57 by fpernes           #+#    #+#             */
/*   Updated: 2016/11/19 17:56:04 by fpernes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	parseh(t_fdfwin *store, int x, int y, int m)
{
	if (store->lin == 201)
		store->lin--;
	if (store->lin > 100)
		x = 1;
	else
		x = 0;
	y = 0;
	m = 0;
	posho(store, x, y, m);
	while (hoparse(store, x, y, m) == -1)
	{
		reduc(store);
		if (store->lin == 100)
			x = 1;
		else
			x = 0;
		y = 0;
		m = 0;
		posho(store, x, y, m);
	}
	parsev(store, x, y, m);
}

int		numbpar(t_fdfwin *store, char *str, int i)
{
	int m;
	int x;
	int y;

	m = 0;
	x = store->x;
	y = store->y;
	if (str[i] == '-')
	{
		store->sign[y][x] = 1;
		i++;
	}
	else
		store->sign[y][x] = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		m *= 10;
		m += (str[i] - 48);
		i++;
	}
	store->tab[y][x] = m;
	return (i);
}

void	parstab(t_fdfwin *store, char *str)
{
	int i;

	i = 0;
	store->x = 0;
	store->y = 0;
	while (store->x != store->col && store->y != store->lin)
	{
		if (str[i] == ' ')
			i++;
		i = numbpar(store, str, i);
		store->x = store->x + 1;
		if (str[i] == ',')
		{
			while (str[i] != ' ')
				i++;
		}
		while (str[i] == ' ')
			i++;
		if (store->x == store->col)
		{
			store->x = 0;
			store->y++;
			i = i + 1;
		}
	}
}

void	posve(t_fdfwin *store, int x, int y, int m)
{
	double o;

	o = store->tab[y][x];
	o--;
	store->x = 10 + ((store->div) * m);
	store->y = 650 - ((store->div / 2) * m);
	if (store->tab[y][x] != 0)
	{
		if (store->sign[y][x] == 1)
		{
			store->y = store->y + (store->div * 2) + (store->div / 2);
			store->y = store->y + (o * store->div);
		}
		else
		{
			store->y = store->y - (store->div * 2) + (store->div / 2);
			store->y = store->y - (o * store->div);
		}
	}
}

void	posho(t_fdfwin *store, int x, int y, int m)
{
	double o;

	o = store->tab[y][x];
	o--;
	store->x = 10 + (store->div * m);
	store->y = 650 + ((store->div / 2) * m);
	if (store->tab[y][x] != 0)
	{
		if (store->sign[y][x] == 1)
		{
			store->y = store->y + (store->div * 2) + (store->div / 2);
			store->y = store->y + (o * store->div);
		}
		else
		{
			store->y = store->y - (store->div * 2) + (store->div / 2);
			store->y = store->y - (o * store->div);
		}
	}
}
