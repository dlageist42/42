/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_delone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:01:05 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:01:06 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_delone(t_hash **hash, void (*f)(void *, size_t))
{
	if (!hash || !*hash)
		return ;
	if (f)
		f((*hash)->value, (*hash)->size);
	free((*hash)->key);
	ft_memdel((void **)hash);
}
