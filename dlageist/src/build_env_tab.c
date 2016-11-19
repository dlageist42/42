/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:10:29 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 16:10:35 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_string(char *key, char *value)
{
	static char buffer[1000];

	ft_memset(buffer, 0, 1000);
	ft_strcat(buffer, key);
	ft_strcat(buffer, "=");
	ft_strcat(buffer, value);
	return (ft_strdup(buffer));
}

static void	add_string(char *key, void *value, size_t size, void *ptr)
{
	int		i;
	char	**tab;

	tab = (char **)ptr;
	i = 0;
	while (tab[i])
		++i;
	tab[i] = build_string(key, (char *)value);
	(void)size;
}

char		**build_env_tab(void)
{
	int		i;
	char	**tab;

	if (!(i = hash_count(g_env)))
		return (NULL);
	++i;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * i)))
		return (NULL);
	hash_foreach(g_env, add_string, (void *)tab);
	return (tab);
}
