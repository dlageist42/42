/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:43:30 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:43:44 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static LP	*search(LP *curr, char *str)
{
	LP *temp;

	if (curr->next)
		temp = curr->next;
	else
		temp = *(lst_get_first());
	while (temp != curr)
	{
		if (ft_strstr(temp->value, str))
			return (temp);
		temp = temp->next ? temp->next : *(lst_get_first());
	}
	return (NULL);
}

void		lst_search(LP **curr, INF *infos)
{
	LP *new;

	if ((new = search(*curr, (char *)infos->str_search)))
	{
		(*curr)->on = 0;
		*curr = new;
		(*curr)->on = 1;
	}
}
