/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:13:46 by dlageist          #+#    #+#             */
/*   Updated: 2015/12/06 15:18:14 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *s, char c)
{
	char	*str;
	int		count;
	int		i;

	str = (char *)s;
	count = 0;
	i = 0;
	while (*str)
	{
		if (i == 1 && *str == c)
			i = 0;
		if (i == 0 && *str != c)
		{
			i = 1;
			count++;
		}
		str++;
	}
	return (count);
}
