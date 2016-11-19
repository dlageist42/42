/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:41:37 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 12:41:44 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	hash_del(t_hash **hash, void (*f)(void *, size_t))
{
	if (!hash || !(*hash))
		return ;
	if ((*hash)->next)
		hash_del(&((*hash)->next), f);
	hash_delone(hash, f);
}
