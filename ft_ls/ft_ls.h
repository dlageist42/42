/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:57:10 by dlageist          #+#    #+#             */
/*   Updated: 2016/03/24 14:57:13 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct 		s_path
{
	char 			*dirname;
	struct s_path	*next;
}					t_path;

typedef struct 		s_args;
{
	char 			*arg
	struct s_args	*next;
}					t_args;

typedef struct 		s_env
{
	int				l;
	int				upr;
	int				lowr;
	int				t;
	int				a;
	t_args			*args;
	t_path			*path;
}					t_env;

void		no_arg(char *path);
t_list		*sort(t_list *name);
int			check_arg(int ac, char **av);

#endif