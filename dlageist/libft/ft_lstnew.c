/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:27:24 by dlageist          #+#    #+#             */
/*   Updated: 2015/12/07 16:40:43 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		if (!(newlist->content = malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
