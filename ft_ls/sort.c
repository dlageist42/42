/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:57:10 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/24 14:57:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**sort(char **name)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (name[j])
	{
		if ((ft_strcmp(name[i], name[j]) > 0))
		{
			ft_swap(name[i], name[j]);
			free(temp);
			temp = NULL;
			i = 0;
			j = 0;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (name);
}