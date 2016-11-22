/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:29:54 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:01:43 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	draw_bar(char *color, int width)
{
	int x;

	x = 0;
	term_write(color);
	while (x++ < width)
		term_write(" ");
}
