/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:57:10 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/24 14:57:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		setenv(t_env *env, int i)
{
	env->l = i;
	env->upr = i;
	env->lowr = i;
	env->t = i;
	env->a = i;
}

int			main(int ac, char **av)
{
	int		i;
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	setenv(env, 0);
	parseArgs(ac, av, env);
	return (0);	
}