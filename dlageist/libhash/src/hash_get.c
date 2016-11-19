/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:09:53 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:09:56 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	*hash_get(t_hash *hash, char *key, BOOL val)
{
	t_hash *current;

	current = hash;
	while (current)
	{
		if (ft_strequ(key, current->key))
			return (val ? current->value : current);
		current = current->next;
	}
	return (NULL);
}
