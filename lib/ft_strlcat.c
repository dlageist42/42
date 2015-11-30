/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:15:00 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/28 18:34:22 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char const* dst, char* src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dstlen = i;
	while (src[i - dstlen] && i < size - 1)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	if (dstlen < size)
		dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}

int	main()
{
	const char src[200] = "abcdefghijklmop";
	char dst[200] = "abc";
	size_t i = 50;

	printf("%zu\n", ft_strlcat(dst, src, i));
	printf("%zu\n", strlcat(dst, src, i));
	return (0);
}
