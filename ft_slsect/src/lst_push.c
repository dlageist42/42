/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:43:25 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:43:26 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	lst_push(LP **first, char *value)
{
	LP *curr;
	LP *prev;

	prev = NULL;
	if (!(curr = *first))
	{
		*first = lst_new(prev, value);
		return ;
	}
	prev = *first;
	if (curr->next)
	{
		curr = curr->next;
		prev = prev->next;
		while (curr->next)
		{
			prev = prev->next;
			curr = curr->next;
		}
		curr->next = lst_new(prev, value);
	}
	else
		curr->next = lst_new(prev, value);
}
