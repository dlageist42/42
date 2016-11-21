/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:41:42 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 14:08:49 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static LP	*choose_curr(LP **curr)
{
	if ((*curr)->next)
		return ((*curr)->next);
	return ((*curr)->prev);
}

void		lst_del(LP **first, LP **curr)
{
	LP		*new_curr;
	INF		*infos;

	infos = get_infos();
	new_curr = NULL;
	if ((get_infos())->nb_params == 1)
		exit_prog();
	if ((*curr)->select)
		infos->nb_selected--;
	if (!(*curr)->prev)
		*first = (*curr)->next;
	else
		(*curr)->prev->next = (*curr)->next;
	if ((*curr)->next)
		(*curr)->next->prev = (*curr)->prev;
	new_curr = choose_curr(curr);
	ft_memdel((void **)curr);
	*curr = new_curr;
	if (*curr)
		(*curr)->on = 1;
}
