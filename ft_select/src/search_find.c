/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:43:37 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:02:51 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	search_find(t_search *search)
{
	t_item	*current;
	t_item	*item;
	int		len;

	len = ft_strlen(search->buffer);
	current = search->select->current;
	item = current->next;
	while (42)
	{
		if (ft_strstr(item->value, search->buffer))
		{
			search->select->current = item;
			if (item->page != current->page)
				search->select->page = item->page;
			select_render(search->select);
			break ;
		}
		if (item->next == current)
			break ;
		item = item->next;
	}
}
