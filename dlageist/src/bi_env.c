/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:08:55 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 16:09:12 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_var(char *key, void *value, size_t size, void *ptr)
{
	ft_putstr(key);
	ft_putchar('=');
	ft_putstr(value);
	ft_putchar('\n');
	(void)size;
	(void)ptr;
}

void			bi_env(char **args)
{
	hash_foreach(g_env, print_var, NULL);
	(void)args;
}
