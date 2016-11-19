/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:25:21 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:25:22 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static BOOL	should_split(char c)
{
	return (ft_isescaped(c) || c == ' ');
}

static char	**split_cmd(char *cmd)
{
	int		i;
	char	*current;
	char	**tab;

	i = 0;
	if (!(tab = ft_strsplitif(cmd, should_split)))
		return (NULL);
	while ((current = tab[i]))
	{
		tab[i++] = ft_strtrim(current);
		free(current);
	}
	return (tab);
}

void		exec_cmd(char *str)
{
	char **cmd;

	str = ft_strdup(parse_vars(str));
	if (!(cmd = split_cmd(str)) || !cmd[0])
	{
		free_tab(cmd);
		return ;
	}
	if (!exec_file(cmd) && !exec_builtin(cmd))
		exec_path(cmd);
	free(str);
	free_tab(cmd);
}
