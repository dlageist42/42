/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:09:31 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/28 17:19:29 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	char	*string1;
	char	*string2;

	i = 0;
	string1 = (char *)s1;
	string2 = (char *)s2;
	if (string1[0] == '\0' && string2[0] != '\0')
		return (-1);
	if (string1[0] != '\0' && string2[0] == '\0')
		return (1);
	if (string1[0] == '\0' && string2[0] == '\0')
		return (0);
	while (string1[i] == string2[i])
	{
		i++;
		if ((string1[i] == '\0') && (string2[i] == '\0'))
			return (0);
	}
	return (string1[i] - string2[i]);
}
