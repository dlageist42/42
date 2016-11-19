/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:36:40 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:36:46 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_var_value(char *str, char **dest)
{
	char	*value;
	char	tmp;
	int		i;

	i = 0;
	while (ft_isalpha(str[i]) || ft_isdigit(str[i]))
		++i;
	tmp = str[i];
	str[i] = 0;
	value = hash_get(g_env, str, TRUE);
	str[i] = tmp;
	*dest = value;
	return (value ? i + 1 : 0);
}

char		*parse_vars(char *str)
{
	static char buffer[4096];
	int			i;
	int			len;
	char		*value;

	i = 0;
	ft_memset(buffer, 0, 4096);
	while (str[i])
	{
		if (str[i] == '$' && (len = get_var_value(str + i + 1, &value)))
		{
			ft_strcat(buffer, value);
			i += len;
			len = 0;
		}
		else
			ft_pushchar(buffer, str[i++]);
	}
	return (buffer);
}
