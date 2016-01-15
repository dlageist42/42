/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:20:04 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/30 17:29:21 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		k;
	size_t	len;

	i = 0;
	j = 0;
	k = 0;
	len = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && n-- >= len)
	{
		k = i;
		j = 0;
		while (s1[k] == s2[j])
		{
			k++;
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
