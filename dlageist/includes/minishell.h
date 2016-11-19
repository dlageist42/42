/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:20:38 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:46:24 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "libhash.h"
# define NBBUILTINS 6
# define CNOT_FOUND "command not found: "
# define FNOT_FOUND "no such file or directory: "
# define FORBIDDEN "permission denied: "

extern t_hash	*g_env;
extern BOOL		g_process_running;
extern BOOL		g_running;

void			init_env(char **envp);
char			**build_env_tab(void);
void			print_error(char *form, char *str1, char *str2);
char			*parse_vars(char *str);
void			del_hash(void *value, size_t size);

/*
**	EXECS
*/

void			exec_cmd(char *str);
void			exec_path(char **cmd);
BOOL			exec_file(char **cmd);
BOOL			exec_builtin(char **cmd);

/*
**	BUILTINS
*/

typedef struct	s_builtins
{
	char	*name;
	void	(*func)(char **args);
}				t_builtins;

void			bi_cd(char **args);
void			bi_exit(char **args);
void			bi_env(char **args);
void			bi_setenv(char **args);
void			bi_unsetenv(char **args);
void			bi_setprompt(char **args);
#endif
