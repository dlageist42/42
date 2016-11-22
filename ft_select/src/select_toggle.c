/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_toggle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:20:03 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:39:20 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_toggle(t_select *select)
{
	if (select->current->selected)
	{
		select->current->selected = FALSE;
		--select->nb_selected;
	}
	else
	{
		select->current->selected = TRUE;
		++select->nb_selected;
	}
	select_render_item(select, select->current);
	select_move(select, DOWN);
	select_render_bar(select);
	search_render(&select->search);
}
