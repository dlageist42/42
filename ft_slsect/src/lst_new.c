/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:43:20 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:43:21 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

LP	*lst_new(LP *prev, char *value)
{
	LP *new;

	if (!(new = (LP *)ft_memalloc(sizeof(LP))))
		return (NULL);
	new->value = value;
	new->prev = prev;
	new->next = NULL;
	return (new);
}
