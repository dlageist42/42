/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:03:29 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:03:34 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_foreach(t_hash *hash
, void (*f)(char *, void *, size_t, void *), void *ptr)
{
	t_hash *current;

	if (!f)
		return ;
	current = hash;
	while (current)
	{
		f(current->key, current->value, current->size, ptr);
		current = current->next;
	}
}
