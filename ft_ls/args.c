/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:57:10 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/24 14:57:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		checkParams(char *str, t_args **argument)
{
	int		i;
	t_arg
	i = 1;
	while (str[i])
	{
		env->l += str[i] == 'l' ? 1 : 0;
		env->l += str[i] == 'l' ? 1 : 0;
		env->l += str[i] == 'l' ? 1 : 0;
		env->l += str[i] == 'l' ? 1 : 0;
		env->l += str[i] == 'l' ? 1 : 0;
	}
}
void		parseArgs(int ac, char **av, t_env *env)
{
	int		i;
	t_args	*argument;
	t_path	*path;

	argument = ft_lstnew(NULL, 0);
	path = ft_lstnew(NULL, 0);
	i = 1;
	--ac;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			checkParams(av[i], &argument);
		}
	}
}