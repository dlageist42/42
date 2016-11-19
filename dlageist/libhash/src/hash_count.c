/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:16:19 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:16:20 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

int		hash_count(t_hash *hash)
{
	int		i;
	t_hash	*current;

	i = 0;
	current = hash;
	while (current)
	{
		++i;
		current = current->next;
	}
	return (i);
}
