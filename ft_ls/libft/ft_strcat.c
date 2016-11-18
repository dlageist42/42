/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:08:32 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/15 08:15:52 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *start;

	if (src == NULL)
		return (dest);
	start = dest;
	dest += ft_strlen(dest);
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (start);
}
