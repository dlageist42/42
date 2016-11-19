/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_getset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:10:03 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:15:46 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

t_hash	*hash_getset(t_hash **hash, char *key, void *value, size_t size)
{
	t_hash *current;

	if (!hash)
		return (NULL);
	if ((current = hash_get(*hash, key, FALSE)))
		return (current);
	return (hash_set(hash, key, value, size));
}
