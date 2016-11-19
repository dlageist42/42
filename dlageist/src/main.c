/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:35:17 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:36:34 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "minishell.h"

t_hash	*g_env = NULL;
BOOL	g_process_running = FALSE;
BOOL	g_running = TRUE;

static void	exec_cmds(char *cmd)
{
	int		i;
	char	**tab;

	if (!(tab = ft_strsplit(cmd, ';')))
		ft_errexit("malloc failed !");
	i = 0;
	while (g_running && tab[i])
		exec_cmd(tab[i++]);
	ft_freetab((void **)tab);
}

static void	add_lvl(void)
{
	char	*str;
	int		i;

	str = hash_getset(&g_env, "SHLVL", "0", 2)->value;
	i = ft_atoi(str);
	++i;
	str = ft_itoa(i);
	hash_set(&g_env, "SHLVL", str, ft_strlen(str) + 1);
	free(str);
}

static void	sig_handler(int id)
{
	if (id == SIGINT)
	{
		ft_putchar('\n');
		return ;
	}
}

int			main(int ac, char **av, char **envp)
{
	char *cmd;

	init_env(envp);
	add_lvl();
	signal(SIGINT, sig_handler);
	while (g_running)
	{
		ft_putstr(hash_getset(&g_env, "MSP", "$> ", 4)->value);
		get_next_line(0, &cmd);
		exec_cmds(cmd);
		ft_memdel((void **)&cmd);
	}
	hash_del(&g_env, del_hash);
	(void)ac;
	(void)av;
	return (0);
}
