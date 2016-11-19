/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:36:52 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:45:26 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *from, char *str1, char *str2)
{
	ft_putstr_fd(from, 2);
	if (str1)
		ft_putstr_fd(str1, 2);
	if (str2)
		ft_putendl_fd(str2, 2);
}
