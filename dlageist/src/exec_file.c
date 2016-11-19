/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:30:54 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:31:01 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include "minishell.h"
#define NOT_FILE_PATH(cmd) (cmd[0][0] != '.' && cmd[0][0] != '/')

static void	run_cmd(char **cmd)
{
	pid_t	father;
	char	**tab;

	father = fork();
	if (father)
	{
		g_process_running = TRUE;
		wait(NULL);
		g_process_running = FALSE;
	}
	else
	{
		execve(cmd[0], cmd, (tab = build_env_tab()));
		ft_freetab((void **)tab);
	}
}

BOOL		exec_file(char **cmd)
{
	if (NOT_FILE_PATH(cmd))
		return (FALSE);
	if (access(cmd[0], F_OK) == -1)
		print_error("minishell: ", FNOT_FOUND, cmd[0]);
	else if (access(cmd[0], X_OK) == -1)
		print_error("minishell: ", FORBIDDEN, cmd[0]);
	else
		run_cmd(cmd);
	return (TRUE);
}
