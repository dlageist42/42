/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:17 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:32:17 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	set_item(t_item *item, int x, int y, int page)
{
	item->x = x;
	item->y = y;
	item->page = page;
}

static void	set_items_pos(t_select *select)
{
	t_item	*current;
	int		x;
	int		y;

	x = 0;
	y = (select->search.i) ? 2 : 1;
	current = select->items;
	while (42)
	{
		if (y == select->size.ws_row - 2)
		{
			x += select->items_width;
			if (x > select->size.ws_col - select->items_width)
			{
				x = 0;
				++select->nb_pages;
			}
			y = (select->search.i) ? 2 : 1;
		}
		set_item(current, x, y, select->nb_pages);
		if (current->next == select->items)
			break ;
		++y;
		current = current->next;
	}
}

void		select_update(t_select *select)
{
	select->active = TRUE;
	select->nb_pages = 1;
	set_items_pos(select);
}
