/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:54:31 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:56:37 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		start_signal_handling(void)
{
	int i;

	i = 1;
	while (i < 32)
		signal(i++, signal_handler);
}

static void	signal_ctrl_z(int sig)
{
	char	ctrl_z[2];
	INF		*infos;

	ctrl_z[0] = 032;
	ctrl_z[1] = 0;
	if (sig == SIGTSTP && isatty(1))
	{
		signal(SIGTSTP, SIG_DFL);
		disable_env();
		restaure_term(get_prev());
		ioctl(0, TIOCSTI, ctrl_z);
		ft_tputs("cl", 1);
	}
	else if (sig == SIGCONT)
	{
		signal(SIGTSTP, signal_handler);
		infos = get_infos();
		reconfigure_term(get_prev());
		fill_infos();
		draw(get_infos(), *(lst_get_first()));
	}
}

void		signal_handler(int sig)
{
	if (sig == SIGINT)
		exit_prog();
	else if (sig == SIGWINCH)
	{
		fill_infos();
		if ((get_infos())->valid_size > 0)
		{
			lst_get_curr_page(*(lst_get_first()), get_infos());
			draw(get_infos(), *(lst_get_first()));
		}
	}
	else if (sig == SIGTSTP || sig == SIGCONT)
		signal_ctrl_z(sig);
	else
	{
		(get_infos())->error = 1;
		(get_infos())->err = sig;
		exit_prog();
	}
}
