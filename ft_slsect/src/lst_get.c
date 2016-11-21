/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:42:08 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:42:52 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

LP		**lst_get_first(void)
{
	static LP *first;

	return (&first);
}

LP		*lst_get_last(LP **first)
{
	LP *curr;

	curr = *first;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

int		lst_get_size(LP **first)
{
	LP	*curr;
	int	i;

	i = 0;
	curr = *first;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i++);
}

int		lst_get_size_line(LP **first)
{
	int	i;
	int	b;
	LP	*curr;

	i = 0;
	b = 0;
	curr = *first;
	while (curr)
	{
		b = ft_strlen(curr->value);
		i = b > i ? b : i;
		curr = curr->next;
	}
	return (i);
}

void	lst_get_curr_page(LP *first, INF *infos)
{
	while (first)
	{
		if (first->on)
		{
			infos->curr_page = first->page;
			break ;
		}
		first = first->next;
	}
}
