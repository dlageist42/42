/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_render_item.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:13:00 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:44:02 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#define VM "✅"

static void	draw_background(int width)
{
	int x;

	x = 0;
	while (x++ < width - 4)
		term_write(" ");
}

static void	print_color(t_filetype type)
{
	static char *colors[] = COLORS;

	if (type != WHT)
		term_write(colors[type]);
}

void		select_render_item(t_select *select, t_item *item)
{
	term_goto_relative(item->x, item->y);
	term_mode_off();
	term_write(EOC);
	if (item->selected)
	{
		term_write(" ");
		term_write(VM);
		term_write("  ");
	}
	else
		term_write("    ");
	print_color(item->type);
	if (item->selected)
		term_mode_rv();
	draw_background(select->items_width);
	term_goto_relative(item->x + 4, item->y);
	if (item == select->current)
		term_underline(TRUE);
	term_write(item->value);
	term_underline(FALSE);
}
