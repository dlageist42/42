/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:18:48 by dlageist          #+#    #+#             */
/*   Updated: 2015/12/06 15:27:47 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *start;

	start = dest;
	dest += ft_strlen(dest);
	while (*src && n-- > 0)
		*(dest++) = *(src++);
	*dest = '\0';
	return (start);
}
