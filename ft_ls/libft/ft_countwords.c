/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:33:42 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/18 11:33:45 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s1, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s1[i])
	{
		if ((i == 0 && s1[i] != c) ||
			(i != 0 && s1[i] != c && s1[i - 1] == c))
			ret++;
		i++;
	}
	return (ret);
}
