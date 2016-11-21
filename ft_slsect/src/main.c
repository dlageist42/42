/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:02:56 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 14:11:31 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

ST		*get_prev(void)
{
	static struct termios prev;

	return (&prev);
}

void	exit_prog(void)
{
	INF *infos;

	infos = get_infos();
	disable_env();
	if (infos->print)
		print_params(*(lst_get_first()));
	if (infos->error)
	{
		ft_putstr_fd("ft_select: received kill signal : ", 2);
		ft_putnbr_fd((get_infos())->err, 2);
		ft_putendl_fd("", 2);
	}
	lst_free(lst_get_first());
	restaure_term(get_prev());
	exit(0);
}

int		main(int ac, char *argv[])
{
	const char		*name_term;
	struct termios	*prev;

	prev = get_prev();
	if (ac == 1)
		return (error("ft_select: Need one param or more", ""));
	if (!(name_term = getenv("TERM")))
		return (error("ft_select: TERM variable empty", ""));
	if (tgetent(NULL, name_term) == -1)
		return (error("ft_select: TERM variable invalide", ""));
	if (reconfigure_term(prev) == -1)
		return (error("ft_select: Error terminal configuration", ""));
	load_params(argv);
	fill_infos();
	start_signal_handling();
	start_select();
	return (0);
}
