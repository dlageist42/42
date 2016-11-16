/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:58:17 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/16 11:58:43 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_total(t_elstinfos *infos)
{
	ft_putstr("total ");
	ft_putnbr(infos->total);
	ft_putchar('\n');
}
