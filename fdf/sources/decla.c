/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decla.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpernes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:31:26 by fpernes           #+#    #+#             */
/*   Updated: 2016/11/19 21:14:59 by fpernes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	decla(t_fdfwin *store)
{
	store->mlx = mlx_init();
	store->win = mlx_new_window(store->mlx, 2000, 1300, "FdF");
	store->tab = createtab(store->lin, store->col);
	store->sign = createtab(store->lin, store->col);
	store->div = 16;
	store->frat1 = 1;
	store->frat2 = .5;
	store->color = 0xFFFFFF;
}

void	reduc(t_fdfwin *store)
{
	mlx_destroy_window(store->mlx, store->win);
	store->win = mlx_new_window(store->mlx, 2000, 1300, "FdF");
	store->div = store->div / 2;
}

void	parsev(t_fdfwin *store, int x, int y, int m)
{
	if (store->lin == 200)
		store->lin = store->lin - 23;
	if (store->lin > 100)
		x = 1;
	else
		x = 0;
	y = 0;
	m = 0;
	posve(store, x, y, m);
	while (veparse(store, x, y, m) == -1)
	{
		reduc(store);
		if (store->lin == 201)
			store->lin = store->lin - 14;
		else if (store->lin > 100)
			x = 1;
		else
			x = 0;
		y = 0;
		m = 0;
		posve(store, x, y, m);
	}
}

int		check(t_fdfwin *store, char *str)
{
	int i;

	i = 0;
	store->o = 0;
	store->p = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n')))
			store->o++;
		i++;
		if (str[i] == '\n')
		{
			if (store->o != store->col)
				return (-1);
			i++;
			store->o = 0;
			store->p++;
		}
	}
	store->p++;
	if (alp(store, str) == -1)
		return (-1);
	return (0);
}

int		alp(t_fdfwin *store, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= '0' && str[i] >= '9') || str[i] == '\n' || str[i] == '\0'
			|| str[i] == '\t' || str[i] == ' ' || (str[i] <= 'Z' &&
			str[i] >= 'A') || (str[i] <= 'z' || str[i] >= 'a'))
			i++;
		else
			return (-1);
	}
	printf("%d\n", store->lin);
	printf("%d\n"), store->col);
	if (store->col == 0 || store->lin == 0)
		return (-1);
	if (store->col != 0 && store->lin == 2)
		return (-1);
	if (store->col == 2 && store->lin == != 0)
		return (-1);
	if (store->p != store->lin)
	{
		store->p--;
		if (store->p != store->lin)
			return (-1);
	}
	return (0);
}
