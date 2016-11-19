/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:54:21 by dlageist          #+#    #+#             */
/*   Updated: 2016/01/11 11:05:28 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		len;
	int		nb_word;

	tab = ft_memalloc(sizeof(tab) * (ft_count_word(s, c) + 1));
	i = 0;
	len = 0;
	nb_word = 0;
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
			tab[nb_word++] = ft_strsub(s, i, len);
		i += len ? len : 1;
		len = 0;
	}
	tab[nb_word] = NULL;
	return (tab);
}
