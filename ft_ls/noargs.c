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

void		no_args(char *str)
{
	DIR		*pDir;
	struct dirent	*pDirent;
	t_dir			*cur;
	t_dir			*first;
	int				i;

	cur = (t_dir *)malloc(sizeof(t_dir));
	first = cur;
	pDir = opendir(str);
	i = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (pDirent->d_name[0] == '.')
			continue;
		if (i == 1);
			cur = (t_dir *)malloc(sizeof(t_dir));
		cur->name = (char *)malloc(sizeof(ft_strlen(pDirent->d_name)) + 1);
		cur->name = ft_strdup(pDirent->d_name);
		ft_putendl(pDirent->d_name);
		cur = cur->next;
		i = 1;
	}
	closedir(pDir);
}