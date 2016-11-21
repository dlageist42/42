/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:42:56 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:43:10 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER *(unsigned int *)buf
#include "ft_select.h"

static LP	*lst_go_to_left(LP **curr, int no)
{
	LP *new;

	if ((*curr)->prev)
		new = (*curr)->prev;
	else
		new = lst_get_last(lst_get_first());
	while (new)
	{
		if (new->y == no)
			return (new);
		if (!new->prev)
			return (new);
		new = new->prev;
	}
	return (new);
}

static LP	*lst_go_to_right(LP **curr, int no)
{
	LP *new;

	if ((*curr)->next)
		new = (*curr)->next;
	else
		new = *(lst_get_first());
	while (new)
	{
		if (new->y == no)
			return (new);
		if (!new->next)
			return (new);
		new = new->next;
	}
	return (new);
}

void		lst_move(LP **curr, LP **first, char *buf)
{
	(*curr)->on = 0;
	if (BUFFER == UP_KEY)
	{
		if ((*curr)->prev)
			*curr = (*curr)->prev;
		else
			*curr = lst_get_last(first);
	}
	else if (BUFFER == DOWN_KEY)
	{
		if ((*curr)->next)
			*curr = (*curr)->next;
		else
			*curr = *first;
	}
	else if (BUFFER == RIGHT_KEY)
		*curr = lst_go_to_right(curr, (*curr)->y);
	else if (BUFFER == LEFT_KEY)
		*curr = lst_go_to_left(curr, (*curr)->y);
	(*curr)->on = 1;
}
