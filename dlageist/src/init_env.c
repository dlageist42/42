/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:34:59 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:35:10 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minishell.h"

void		init_env(char **envp)
{
	int		i;
	char	**tab;

	i = 0;
	while (envp[i])
	{
		if (!(tab = ft_strsplit(envp[i], '=')))
			ft_errexit("malloc failed");
		hash_set(&g_env, tab[0], tab[1], ft_strlen(tab[1]) + 1);
		ft_freetab((void **)tab);
		++i;
	}
}
