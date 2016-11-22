/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:34:12 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:02:58 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	search_remove(t_search *search)
{
	if (!search->i)
		return ;
	search->buffer[--search->i] = 0;
	if (!search->i)
	{
		select_update(search->select);
		select_render(search->select);
	}
	else
		search_render(search);
}
