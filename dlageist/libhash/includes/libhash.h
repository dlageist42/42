/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libhash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:16:43 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 15:16:44 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHASH_H
# define LIBHASH_H
# include <stdlib.h>
# include "libft.h"

typedef struct s_hash	t_hash;
struct					s_hash
{
	char	*key;
	void	*value;
	size_t	size;
	t_hash	*next;
};

int						hash_count(t_hash *hash);
void					hash_del(t_hash **hash, void (*f)(void *, size_t));
void					hash_delone(t_hash **hash,
void (*f)(void *, size_t));

void					hash_del(t_hash **hash,
void (*f)(void *, size_t));

t_hash					*hash_new(char *key, void *value, size_t size);
void					hash_foreach(t_hash *hash
, void (*f)(char *, void *, size_t, void *), void *ptr);

void					*hash_get(t_hash *hash, char *key, BOOL val);
t_hash					*hash_getset(t_hash **hash, char *key, void *value
, size_t size);
t_hash					*hash_set(t_hash **hash, char *key, void *value,
size_t size);
void					hash_unset(t_hash **hash, char *key
, void (*f)(void *, size_t));

#endif
