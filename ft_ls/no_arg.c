/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:57:10 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/24 14:57:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		no_arg(char *path)
{
	DIR				*pDir;
	struct dirent	*pDirent;
	int				i;
	t_list			*name;

	name = NULL;
	i = 0;
	pDir = opendir(path);
	while((pDirent = readdir(pDir)))
	{
		if (pDirent->d_name[0] != '.')
		{
			name->content = (char*)malloc(sizeof(t_list) * ft_strlen(pDirent->d_name));
			name->content = ft_strdup(pDirent->d_name);
			name = name->next;
			i++;
		}
	}
	name->next = NULL;
	closedir(pDir);	
}

//Manque Stockage de chaque nom, tri + affichage