/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:09 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 21:02:03 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_filetype	get_file_type(char *path)
{
	static mode_t		modes[] = MODES;
	static struct stat	estat;
	int					i;

	if (lstat(path, &estat) == -1)
		return (7);
	i = 0;
	while (i < 7)
	{
		if ((estat.st_mode & S_IFMT) == modes[i])
			return (i);
		++i;
	}
	return (7);
}

static t_item		*item_push(t_item **list, t_item *last, char *value)
{
	t_item			*item;
	t_item			*current;

	item = (t_item *)ft_memalloc(sizeof(t_item));
	item->value = value;
	item->type = get_file_type(value);
	if (last)
	{
		item->prev = last;
		return (last->next = item);
	}
	if (!(current = *list))
		return (*list = item);
	while (current->next)
		current = current->next;
	item->prev = current;
	return (current->next = item);
}

static void			setup(t_select *select)
{
	ft_bzero(select, sizeof(t_select));
	ft_bzero(&select->search, sizeof(t_search));
	ft_bzero(select->search.buffer, sizeof(30));
	select->search.select = select;
}

void				select_init(t_select *select, char **av)
{
	int		i;
	int		len;
	t_item	*last;

	setup(select);
	i = 0;
	last = NULL;
	select->page = 1;
	while (av[i])
	{
		last = item_push(&(select->items), last, av[i]);
		if ((len = ft_strlen(av[i++])) > select->items_width)
			select->items_width = len;
		++select->total;
	}
	select->items_width += 5;
	select->items->prev = last;
	last->next = select->items;
	select->current = select->items;
}
