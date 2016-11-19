/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:10:16 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 16:10:24 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_unsetenv(char **args)
{
	int i;

	i = 0;
	if (!args[0])
		return (print_error("unsetenv: ", "you given no key\n", NULL));
	while (args[i])
		hash_unset(&g_env, args[i++], del_hash);
}
