
#include "fdf.h"

void	oparseve(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y + 1][x])
		mmoinsve(store, x, y, o);
	if (store->tab[y][x] < store->tab[y + 1][x])
		mmoinsve(store, x, y, o);
	if (store->tab[y][x] > store->tab[y + 1][x])
		mmoinsve(store, x, y, o);
}

void	dparseve(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y + 1][x])
		pplusve(store, x, y, o);
	if (store->tab[y][x] < store->tab[y + 1][x])
		pplusve(store, x, y, o);
	if (store->tab[y][x] > store->tab[y + 1][x])
		pplusve(store, x, y, o);
}

void	tparseve(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y + 1][x])
		egalve(store);
	if (store->tab[y][x] < store->tab[y + 1][x])
		tplusve(store, x, y, o);
	if (store->tab[y][x] > store->tab[y + 1][x])
		tmoinsve(store, x, y, o);
}

void	tmoinsve(t_fdfwin *store, int x, int y, double o)
{
	int i;

	i = 0;
	o = store->tab[y][x] - store->tab[y + 1][x];
	o = store->div * o;
	if (store->tab[y][x] != 0 && store->tab[y + 1][x] != 0)
		o = o - (store->div / 2);
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

void	tplusve(t_fdfwin *store, int x, int y, double o)
{
	int i;

	i = 0;
	o = store->tab[y + 1][x] - store->tab[y][x];
	o = store->div * o;
	o = o + store->div;
	if (store->tab[y][x] != 0 && store->tab[y + 1][x] != 0)
		o = o - (store->div / 2);
	while (i < o)
	{
		mlx_pixel_put(store->mlx, store->win, store->x, store->y, store->color);
		store->x = store->x + (double)store->div / o;
		store->y = store->y + store->frat1;
		i++;
	}
}
