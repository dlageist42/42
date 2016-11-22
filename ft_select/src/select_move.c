/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:17:45 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:27:34 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static	t_item		*get_right(t_select *select)
{
	t_item *current;

	current = select->current->next;
	while (42)
	{
		if (current == select->current)
			return (select->current);
		if (current->y == select->current->y)
			return (current);
		if (current->page != current->next->page
		&& current->y < select->current->y)
			return (current);
		if (current->next == select->items &&
			select->current->x != current->x)
			return (current);
		current = current->next;
	}
}

static t_item		*get_left(t_select *select)
{
	t_item *current;

	current = select->current->prev;
	while (42)
	{
		if (current == select->current)
			return (select->current);
		if (current->y == select->current->y)
			return (current);
		if (current->page != current->next->page
		&& current->y < select->current->y)
			return (current);
		current = current->prev;
	}
}

void				select_move(t_select *select, t_direction direction)
{
	t_item *item;
	t_item *current;

	current = select->current;
	if (direction == UP || direction == DOWN)
		item = (direction == UP) ? current->prev : current->next;
	else
		item = (direction == LEFT) ? get_left(select) : get_right(select);
	select->current = item;
	if (item->page != select->page)
	{
		select->page = item->page;
		select_render(select);
	}
	else
	{
		select_render_item(select, current);
		select_render_item(select, item);
		search_render(&select->search);
	}
}
