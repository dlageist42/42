

#include "fdf.h"

void	oparseho(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y][x + 1])
		mmoinsho(store, x, y, o);
	if (store->tab[y][x] < store->tab[y][x + 1])
		mmoinsho(store, x, y, o);
	if (store->tab[y][x] > store->tab[y][x + 1])
		mmoinsho(store, x, y, o);
}

void	dparseho(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y][x + 1])
		pplusho(store, x, y, o);
	if (store->tab[y][x] < store->tab[y][x + 1])
		pplusho(store, x, y, o);
	if (store->tab[y][x] > store->tab[y][x + 1])
		pplusho(store, x, y, o);
}

void	tparseho(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y][x + 1])
		egalho(store);
	if (store->tab[y][x] < store->tab[y][x + 1])
		tmoinsho(store, x, y, o);
	if (store->tab[y][x] > store->tab[y][x + 1])
		tplusho(store, x, y, o);
}

void	tmoinsho(t_fdfwin *store, int x, int y, double o)
{
	int i;

	i = 0;
	o = store->tab[y][x + 1] - store->tab[y][x];
	o = store->div * o;
	if (store->tab[y][x] != 0 && store->tab[y][x + 1] != 0)
		o = o - (store->div / 2);
	if (o == (store->div / 2))
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

void	tplusho(t_fdfwin *store, int x, int y, double o)
{
	int i;

	i = 0;
	o = store->tab[y][x] - store->tab[y][x + 1];
	o = store->div * o;
	if (store->tab[y][x] != 0 && store->tab[y][x + 1] != 0)
		o = o + (store->div / 2);
	if (o == (store->div / 2))
		o = o + (store->div / 2);
	while (i < o)
	{
		mlx_pixel_put(store->mlx, store->win, store->x, store->y, store->color);
		store->x = store->x + (double)store->div / o;
		if (o == store->div && (store->tab[y][x] != 0 || store->tab[y + 1][x]))
			store->y = store->y - store->frat2;
		else
			store->y = store->y - store->frat1;
		i++;
	}
}
