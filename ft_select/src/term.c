/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:33:11 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:35:03 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int g_fd = 1;

static int	putch(int c)
{
	write(g_fd, &c, 1);
	return (c);
}

void		term_end(void)
{
	term_write(tgetstr("te", NULL));
	close(g_fd);
}

int			term_start(char *tty)
{
	g_fd = open(tty, O_WRONLY);
	term_write(tgetstr("ti", NULL));
	return (g_fd);
}

void		term_write(char *str)
{
	tputs(str, 1, putch);
}
