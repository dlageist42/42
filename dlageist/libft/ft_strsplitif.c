/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 12:43:04 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 12:43:05 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count(char const *s1, BOOL (*f)(char c))
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s1[i])
	{
		if ((i == 0 && !(f)(s1[i])) ||
			(i != 0 && !(f)(s1[i]) && (f)(s1[i - 1])))
			ret++;
		i++;
	}
	return (ret);
}

char	**ft_strsplitif(char const *s, BOOL (*f)(char c))
{
	int		i;
	int		len;
	int		wi;
	char	**as;

	if (!s)
		return (NULL);
	as = ft_memalloc(sizeof(as) * (count(s, f) + 1));
	i = 0;
	len = 0;
	wi = 0;
	if (!as)
		return (NULL);
	while (s[i])
	{
		while (s[i + len] && !f(s[i + len]))
			len++;
		if (len)
			as[wi++] = ft_strsub(s, i, len);
		i += len ? len : 1;
		len = 0;
	}
	as[wi] = NULL;
	return (as);
}
