/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:11:03 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:25:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

BOOL	exec_builtin(char **cmd)
{
	static	t_builtins	builtins[] = {
									{"cd", bi_cd},
									{"exit", bi_exit},
									{"env", bi_env},
									{"setenv", bi_setenv},
									{"unsetenv", bi_unsetenv},
									{"setprompt", bi_setprompt}};
	int					i;

	i = 0;
	while (i < NBBUILTINS)
	{
		if (ft_strequ(cmd[0], builtins[i].name))
		{
			builtins[i].func(cmd + 1);
			return (TRUE);
		}
		++i;
	}
	return (FALSE);
}
