/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:22:54 by dlageist          #+#    #+#             */
/*   Updated: 2016/01/15 09:40:38 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	len;
	int	start;

	len = ft_strlen(s);
	start = 0;
	len--;
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
	{
		start++;
		if (!s[start])
			return (ft_strnew(0));
	}
	while (s[len] == '\n' || s[len] == '\t' || s[len] == ' ')
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
