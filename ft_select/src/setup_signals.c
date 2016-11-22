/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:45:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:48:14 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_select *g_select;

static void	resize(int sig)
{
	ioctl(0, TIOCGWINSZ, &(g_select->size));
	select_update(g_select);
	g_select->page = g_select->current->page;
	select_render(g_select);
	(void)sig;
}

static void	stop_cont(int sig)
{
	static struct termios	term;
	char					cp[2];

	cp[0] = 032;
	cp[1] = 0;
	if (sig == SIGTSTP)
	{
		if (!isatty(1))
			return ;
		term_clear();
		term_show_cursor(TRUE);
		term_end();
		tcgetattr(0, &term);
		tcsetattr(0, TCSANOW, &g_select->term);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
	else if (sig == SIGCONT)
	{
		signal(SIGTSTP, stop_cont);
		tcsetattr(0, TCSANOW, &term);
		g_select->fd = term_start(ttyname(0));
		resize(0);
	}
}

static void	handle_sig(int i)
{
	term_show_cursor(TRUE);
	term_end();
	tcsetattr(0, TCSANOW, &g_select->term);
	ft_putendl_fd("ft_select was forced to exit :/ !", 2);
	select_quit(g_select, FALSE);
	(void)i;
}

void		setup_signals(t_select *select)
{
	int i;

	g_select = select;
	i = 0;
	while (i++ < 31)
	{
		if (i == SIGWINCH)
			signal(i, resize);
		else if (i == SIGTSTP || i == SIGCONT)
			signal(i, stop_cont);
		else
			signal(i, handle_sig);
	}
	resize(0);
}
