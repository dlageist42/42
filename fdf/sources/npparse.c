/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npparse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpernes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:36:24 by fpernes           #+#    #+#             */
/*   Updated: 2016/11/03 14:40:06 by fpernes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	venegparse(t_fdfwin *store, int x, int y, double o)
{
	if (store->sign[y][x] == 1 && store->sign[y + 1][x] == 0)
		oparseve(store, x, y, o);
	if (store->sign[y][x] == 0 && store->sign[y + 1][x] == 1)
		dparseve(store, x, y, o);
	if (store->sign[y][x] == 1 && store->sign[y + 1][x] == 1)
		tparseve(store, x, y, o);
}

void	veposparse(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y + 1][x])
		egalve(store);
	if (store->tab[y][x] < store->tab[y + 1][x])
		moinsve(store, x, y, o);
	if (store->tab[y][x] > store->tab[y + 1][x])
		plusve(store, x, y, o);
}

void	honegparse(t_fdfwin *store, int x, int y, double o)
{
	if (store->sign[y][x] == 1 && store->sign[y][x + 1] == 0)
		oparseho(store, x, y, o);
	if (store->sign[y][x] == 0 && store->sign[y][x + 1] == 1)
		dparseho(store, x, y, o);
	if (store->sign[y][x] == 1 && store->sign[y][x + 1] == 1)
		tparseho(store, x, y, o);
}

void	hoposparse(t_fdfwin *store, int x, int y, double o)
{
	if (store->tab[y][x] == store->tab[y][x + 1])
		egalho(store);
	if (store->tab[y][x] < store->tab[y][x + 1])
		moinsho(store, x, y, o);
	if (store->tab[y][x] > store->tab[y][x + 1])
		plusho(store, x, y, o);
}

void	freetab(int **tableau)
{
	free(tableau[0]);
	free(tableau);
}
