/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:55:36 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/28 17:01:51 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	x;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	x = (unsigned char)c;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		*(s1 + i) = *(s2 + i);
		if (s1[i] == x)
		{
			i += 1;
			return ((char *)dest + i);
		}
		i++;
	}
	return (NULL);
}
