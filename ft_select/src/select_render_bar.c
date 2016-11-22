/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_render_bar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 04:20:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:32:07 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	draw_selected(t_select *select)
{
	term_goto_relative(4, select->size.ws_row - 1);
	ft_putnbr_fd(select->nb_selected, select->fd);
	ft_putchar_fd('/', select->fd);
	ft_putnbr_fd(select->total, select->fd);
	ft_putstr_fd(" selected", select->fd);
}

static void	draw_pages(t_select *select)
{
	int offset;

	offset = ft_getdecade(select->nb_pages) + ft_getdecade(select->page);
	offset += 10;
	term_goto_relative(select->size.ws_col - offset, select->size.ws_row - 1);
	ft_putstr_fd("page ", select->fd);
	ft_putnbr_fd(select->page, select->fd);
	ft_putchar_fd('/', select->fd);
	ft_putnbr_fd(select->nb_pages, select->fd);
}

void		select_render_bar(t_select *select)
{
	term_goto_relative(0, select->size.ws_row - 1);
	term_mode_off();
	term_write(EOC);
	draw_bar(CGREY, select->size.ws_col);
	draw_selected(select);
	draw_pages(select);
	term_write(EOC);
}
