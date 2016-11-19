/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:20:31 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/19 17:46:12 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

typedef struct	s_fdslot
{
	int				fd;
	char			*buffer;
	char			*head;
	struct s_fdslot *next;
}				t_fdslot;
int				get_next_line(int const fd, char **line);
#endif
