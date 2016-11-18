/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elst_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:17:08 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/18 13:17:10 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	elst_del(t_elst *entry)
{
	free(entry->path);
	if (g_long_display)
	{
		free(entry->nlink);
		free(entry->strtime);
		free(entry->owner);
		free(entry->group);
	}
	if (entry->strsize)
		free(entry->strsize);
	if (entry->major)
	{
		free(entry->major);
		free(entry->minor);
	}
	free(entry);
}
