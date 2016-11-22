/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:18:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:02:35 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	search_add(t_search *search, char c)
{
	if (search->i == 28)
		return ;
	search->buffer[search->i++] = c;
	if (search->i == 1)
	{
		select_update(search->select);
		select_render(search->select);
	}
	else
		search_render(search);
}
