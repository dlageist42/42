/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:09:38 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 16:09:44 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		bi_setenv(char **args)
{
	if (!args[0])
		return (bi_env(args));
	hash_set(&g_env, args[0], args[1] ? args[1] : "",
	args[1] ? ft_strlen(args[1]) + 1 : 0);
}
