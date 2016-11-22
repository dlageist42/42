/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_goto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 19:26:10 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:26:11 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_goto(t_select *select, char c)
{
	t_item *current;
	t_item *item;

	current = select->current;
	item = current->next;
	while (item != current)
	{
		if (ft_strchr(item->value, c))
		{
			select->current = item;
			if (current->page != item->page)
			{
				select->page = item->page;
				select_render(select);
			}
			else
			{
				select_render_item(select, current);
				select_render_item(select, item);
			}
			return ;
		}
		item = item->next;
	}
}
