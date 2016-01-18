/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:58:24 by dlageist          #+#    #+#             */
/*   Updated: 2015/12/07 16:40:31 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	if (!(temp = (char *)malloc(sizeof(*temp) * n)))
		return (NULL);
	ft_memcpy(temp, src, n);
	ft_memcpy(dest, temp, n);
	free(temp);
	return (dest);
}
