/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:57:10 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/24 14:57:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					compare(t_dir *l, t_dir *r)
{
	return (ft_strcmp(l->name, r->name));
}

void				add(t_dir **node, char *name, int (*cmp)(t_dir *l, t_dir *r))
{
	t_dir			*new;

	if (!(new = (t_dir *)malloc(sizeof(t_dir))))
		exit (1);
	if (!(new->name = (char *)malloc(sizeof(char) * ft_strlen(name) + 1)))
		exit (1);
	new->name = ft_strdup(name);
	while (*node != NULL)
	{
		if (cmp(*node, new) > 0)
			break;
		node = &(*node)->next;
	}
	new->next = *node;
	*node = new;
}

void				print_list(t_dir *list)
{
	while (list != NULL)
	{
		ft_putendl(list->name);
		list = list->next;
	}
}

void				no_args(char *path)
{
	DIR				*pDir;
	struct dirent	*pDirent;
	t_dir			*cur;

	cur = (t_dir *)malloc(sizeof(t_dir));
	cur = NULL;
	pDir = opendir(path);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (pDirent->d_name[0] == '.')
			continue;
		add(&cur, pDirent->d_name, compare);
	}
	while (cur)
	{
		ft_putendl(cur->name);
		cur = cur->next;
	}
	closedir(pDir);
}