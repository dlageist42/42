/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:10:53 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/21 15:43:16 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int size;

	size = ft_strlen(s);
	dup = ft_memalloc(size);
	if (!dup)
		return (NULL);
	return (ft_memcpy(dup, (char*)s, size + 1));
}
