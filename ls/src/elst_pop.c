/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:23:46 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/16 10:24:22 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elst		*elst_pop(t_elst **begin)
{
	t_elst	*elem;

	if (!*begin)
		return (NULL);
	elem = *begin;
	*begin = elem->next;
	elem->next = NULL;
	return (elem);
}
