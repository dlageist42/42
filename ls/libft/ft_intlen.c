/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:59:16 by dlageist          #+#    #+#             */
/*   Updated: 2016/10/17 13:59:56 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int number)
{
	int length;

	length = 0;
	if (number == 0)
		return (0);
	if (number < 0)
		length++;
	while (number != 0)
	{
		length++;
		number = number / 10;
	}
	return (length);
}
