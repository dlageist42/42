/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:15:59 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:16:00 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

static t_hash	*reset(t_hash *item, void *value, size_t size)
{
	if (item->value)
		free(item->value);
	if (value)
	{
		if (!(item->value = ft_memalloc(size)))
			return (item);
		ft_memcpy(item->value, value, size);
	}
	else
		item->value = NULL;
	item->size = value ? size : 0;
	return (item);
}

t_hash			*hash_set(t_hash **hash, char *key, void *value, size_t size)
{
	t_hash *current;

	if (!hash)
		return (NULL);
	current = *hash;
	while (current)
	{
		if (ft_strequ(key, current->key))
			return (reset(current, value, size));
		if (!current->next)
			return (current->next = hash_new(key, value, size));
		current = current->next;
	}
	return (*hash = hash_new(key, value, size));
}
