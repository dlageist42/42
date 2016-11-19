/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:15:52 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:15:53 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	*hash_new(char *key, void *value, size_t size)
{
	t_hash *new;

	if (!key || !(new = ft_memalloc(sizeof(t_hash))))
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
	{
		if (!(new->value = ft_memalloc(size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->value, value, size);
		new->size = size;
	}
	else
	{
		new->value = NULL;
		new->size = 0;
	}
	return (value ? new : NULL);
}
