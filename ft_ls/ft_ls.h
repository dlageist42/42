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
#include <string.h>
#include "libft/libft.h"

typedef struct 		s_dir
{
	char 			*name;
	struct s_dir	*next;
}					t_dir;

void		no_args(char *str);
int			compare(t_dir *l, t_dir *r);
void		add(t_dir **pp, char *value, int (*cmp)(t_dir *l, t_dir *r));

#endif