/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:11:44 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:25:37 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	search_reset(t_search *search)
{
	ft_bzero(search->buffer, 30);
	search->i = 0;
	select_update(search->select);
	select_render(search->select);
}
