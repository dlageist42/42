/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:42:02 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:42:03 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	lst_free(LP **first)
{
	if (*first)
	{
		if ((*first)->next)
			lst_free(&(*first)->next);
		ft_memdel((void **)first);
	}
}
