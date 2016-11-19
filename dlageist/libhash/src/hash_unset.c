/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:16:09 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:16:10 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_unset(t_hash **hash, char *key, void (*f)(void *, size_t))
{
	t_hash *current;
	t_hash *tmp;

	if (!hash || !(current = *hash))
		return ;
	if (ft_strequ(key, current->key))
	{
		tmp = current->next;
		f(current->value, current->size);
		free(current->key);
		free(current);
		return ((void)(*hash = tmp));
	}
	while (current->next)
	{
		if (ft_strequ(key, current->next->key))
		{
			tmp = current->next->next;
			f(current->next->value, current->next->size);
			free(current->next->key);
			free(current->next);
			return ((void)(current->next = tmp));
		}
		current = current->next;
	}
}
