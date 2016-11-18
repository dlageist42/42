/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:17:18 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/18 13:17:19 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elst	*elst_pop(t_elst **begin)
{
	t_elst *elem;

	if (!*begin)
		return (NULL);
	elem = *begin;
	*begin = elem->next;
	elem->next = NULL;
	return (elem);
}
