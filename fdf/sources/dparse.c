/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dparse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpernes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:07:31 by fpernes           #+#    #+#             */
/*   Updated: 2016/11/19 16:33:31 by fpernes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hoparse(t_fdfwin *store, int x, int y, int m)
{
	static double o;

	while ((y + 1) != store->lin)
	{
		if (store->x < 0 || store->x > 2100 || store->y < 0 || store->y > 1300)
			return (-1);
		o = 0;
		if (store->sign[y][x] == 1 || store->sign[y][x + 1] == 1)
			honegparse(store, x, y, o);
		else
			hoposparse(store, x, y, o);
		x++;
		if ((x + 1) == store->col)
		{
			m++;
			if (store->lin > 100)
				x = 1;
			else
				x = 0;
			y++;
			posho(store, x, y, m);
		}
	}
	return (0);
}

int	veparse(t_fdfwin *store, int x, int y, int m)
{
	static double o;

	while (x != store->col)
	{
		if (store->x < 0 || store->x > 2100 || store->y < 0 || store->y > 1300)
			return (-1);
		o = 0;
		if (store->sign[y][x] == 1 || store->sign[y + 1][x] == 1)
			venegparse(store, x, y, o);
		else
			veposparse(store, x, y, o);
		y++;
		if ((y + 2) == store->lin)
		{
			m++;
			y = 0;
			x++;
			posve(store, x, y, m);
		}
	}
	return (0);
}
