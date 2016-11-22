/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 10:10:11 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:44:34 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#define MG "🔎"

static void	draw_field(t_search *search)
{
	term_goto_relative(4, 0);
	term_write(MG);
	term_write("  ");
	term_write(search->buffer);
	term_show_cursor(TRUE);
}

void		search_render(t_search *search)
{
	t_select *select;

	if (!search->i)
	{
		term_show_cursor(FALSE);
		return ;
	}
	select = search->select;
	term_go_home();
	term_mode_off();
	draw_bar(CGREY, select->size.ws_col);
	draw_field(search);
	term_write(EOC);
}
