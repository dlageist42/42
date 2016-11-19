/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:19:35 by dlageist          #+#    #+#             */
/*   Updated: 2015/11/28 13:19:40 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((s1 == NULL && s2 == NULL) || (n == 0))
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	else
	{
		while (*s1 != '\0' && s2 != '\0' && n-- > 0)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		return (1);
	}
}
