
#include "fdf.h"
#include <stdio.h>

void	egalho(t_fdfwin *store)
{
	int i;

	i = 0;
	while (i < store->div)
	{
		mlx_pixel_put(store->mlx, store->win, store->x, store->y, store->color);
		store->x = store->x + store->frat1;
		store->y = store->y - store->frat2;
		i++;
	}
}

void	moinsho(t_fdfwin *store, int x, int y, double o)
{
	int i;
	int tmp;

	i = 0;
	o = store->tab[y][x + 1] - store->tab[y][x];
	o = store->div * o;
	o = o + store->div;
	if (store->tab[y][x] != 0 && store->tab[y][x + 1] != 0)
		o = o - (store->div / 2);
	if (o == (store->div / 2))
		o = o + (store->div / 2);
	while (i < o)
	{
		mlx_pixel_put(store->mlx, store->win, store->x, store->y, store->color);
		store->x = store->x + (double)store->div / o;
		if (o == store->div && store->tab[y][x] != 0)
			store->y = store->y - store->frat2;
		else
			store->y = store->y - store->frat1;
		i++;
	}
}

void	plusho(t_fdfwin *store, int x, int y, double o)
{
	int i;

	i = 0;
	o = store->tab[y][x] - store->tab[y][x + 1];
	o = store->div * o;
	if (store->tab[y][x] != 0 && store->tab[y][x + 1] != 0)
		o = o - (store->div / 2);
	while (i < o)
	{
		mlx_pixel_put(store->mlx, store->win, store->x, store->y, store->color);
		store->x = store->x + (double)store->div / o;
		store->y = store->y + store->frat1;
		i++;
	}
}

void	mmoinsho(t_fdfwin *store, int x, int y, double o)
{
	int i;

	i = 0;
	o = store->tab[y][x] + store->tab[y][x + 1];
	o = store->div * o;
	o = o + (store->div * 2);
	if (store->tab[y][x] != 0 && store->tab[y][x + 1] != 0)
		o = o + (store->div / 2);
	while (i < o)
	{
		mlx_pixel_put(store->mlx, store->win, store->x, store->y, store->color);
		store->x = store->x + (double)store->div / o;
		store->y = store->y - store->frat1;
		i++;
	}
}

void	pplusho(t_fdfwin *store, int x, int y, double o)
{
	int i;

	i = 0;
	o = store->tab[y][x + 1] + store->tab[y][x];
	o = store->div * o;
	o = store->div + o;
	if (store->tab[y][x] != 0 && store->tab[y][x + 1] != 0)
		o = o + (store->div / 2);
	if (o == store->div / 2)
		o = o + (store->div / 2);
	while (i < o)
	{
		mlx_pixel_put(store->mlx, store->win, store->x, store->y, store->color);
		store->x = store->x + (double)store->div / o;
		if (o == store->div && (store->tab[y][x] != 0 || store->tab[y + 1][x]))
			store->y = store->y + store->frat2;
		else
			store->y = store->y + store->frat1;
		i++;
	}
}
