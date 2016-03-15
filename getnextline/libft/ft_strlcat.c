/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:15:00 by dlageist          #+#    #+#             */
/*   Updated: 2015/12/03 16:18:19 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char const *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	char	*str;

	str = (char *)dst;
	i = 0;
	while (str[i] && i < size)
		i++;
	dstlen = i;
	while (src[i - dstlen] && i < size - 1)
	{
		str[i] = src[i - dstlen];
		i++;
	}
	if (dstlen < size)
		str[i] = '\0';
	return (dstlen + ft_strlen(src));
}
