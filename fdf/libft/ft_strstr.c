/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:21:50 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/30 17:30:28 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i])
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
