/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:48:15 by dlageist          #+#    #+#             */
/*   Updated: 2015/12/06 15:08:28 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!(new = ft_lstnew(0, 0)))
		return (NULL);
	if (lst && f)
	{
		new = f(lst);
		if (lst->next != NULL)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
