/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:27:54 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:25:43 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_del(t_select *select)
{
	t_item *to_del;

	to_del = select->current;
	if (to_del->next == to_del)
		select_quit(select, FALSE);
	to_del->prev->next = to_del->next;
	to_del->next->prev = to_del->prev;
	select->current = to_del->next;
	if (to_del == select->items)
		select->items = to_del->next;
	if (to_del->selected)
		--select->nb_selected;
	--select->total;
	free(to_del);
	select_update(select);
	select_render(select);
}
