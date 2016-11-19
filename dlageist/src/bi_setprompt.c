/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setprompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:09:55 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:46:48 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"
#define CDEF "\033[00m"
#define CG "\033[32m"

void	bi_setprompt(char **args)
{
	char *str;
	char *parsed;

	(void)args;
	ft_putstr("Enter new prompt: ");
	if (get_next_line(0, &str) != 1)
		return ;
	parsed = parse_vars(str);
	hash_set(&g_env, "MSP", parsed, ft_strlen(parsed) + 1);
	ft_putstr(CG);
	ft_putstr("Prompt set successfully !");
	ft_putendl(CDEF);
	free(str);
}
