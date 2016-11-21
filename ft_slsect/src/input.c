/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:40:21 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 14:15:48 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER *(unsigned int *)buf
#include "ft_select.h"

static void	exit_print(char *buf)
{
	if (BUFFER == RET_KEY)
		(get_infos())->print = 1;
	exit_prog();
}

static void	select_entry(LP **curr, INF *infos)
{
	(*curr)->select = (*curr)->select ? 0 : 1;
	infos->nb_selected += (*curr)->select ? 1 : -1;
	(*curr)->on = 0;
	*curr = (*curr)->next ? (*curr)->next : *(lst_get_first());
	(*curr)->on = 1;
}

static void	search(LP **curr, INF *infos, char *buf)
{
	if (BUFFER > 96 && BUFFER < 123)
	{
		infos->search = 1;
		if (infos->index < 29 && (int)(27 + ft_strlen(infos->str_search)) <
			infos->width)
			infos->str_search[infos->index++] = buf[0];
	}
	else if (infos->search && BUFFER == DEL_KEY)
	{
		infos->str_search[--infos->index] = 0;
		if (!infos->index)
			infos->search = 0;
	}
	else if (BUFFER == RET_KEY && infos->search)
		lst_search(curr, infos);
}

void		input_handler(LP **first, INF *infos, LP **curr, char *buf)
{
	if (BUFFER == UP_KEY || BUFFER == DOWN_KEY || BUFFER == LEFT_KEY ||
		BUFFER == RIGHT_KEY)
		lst_move(curr, first, buf);
	else if ((BUFFER > 96 && BUFFER < 123) || (infos->search &&
		(BUFFER == RET_KEY || BUFFER == DEL_KEY)))
		search(curr, infos, buf);
	else if (BUFFER == SPACE_KEY)
		select_entry(curr, infos);
	else if (BUFFER == SUP_KEY)
		lst_del(first, curr);
	else if (BUFFER == RET_KEY || BUFFER == ESC_KEY)
		exit_print(buf);
	infos->curr_page = (*curr)->page;
}
