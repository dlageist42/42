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
	t_list			*name;

	name = NULL;
	pDir = opendir(path);
	while((pDirent = readdir(pDir)) != NULL)
	{
		if (pDirent->d_name[0] != '.')
		{
			name = (t_list *)malloc(sizeof(t_list));
			name->content = (char*)malloc(sizeof(char)*ft_strlen(
				pDirent->d_name));
			ft_strcpy(name->content, pDirent->d_name);
			ft_putstr(name->content);
			ft_putchar('\n');
			name = name->next;
		}
	}
	closedir(pDir);
}


//NE RIEN TOUCHER, FT_LS SANS RIEN MARCHE