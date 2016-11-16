/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:22:09 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/16 10:22:22 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elst	*elst_add(t_elst **begin, t_elst *last, t_elst *new)
{
	if (!*begin)
		return (*begin = new);
	return (last->next = new);
}
