/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:56:42 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:57:02 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	enable_env(void)
{
	ft_tputs("ti", 1);
	ft_tputs("vi", 1);
	(get_infos())->load_cap = 1;
}

void	disable_env(void)
{
	ft_tputs("ve", 1);
	ft_tputs("te", 1);
	(get_infos())->load_cap = 0;
}

int		restaure_term(ST *prev)
{
	tcsetattr(0, TCSANOW, prev);
	close((get_infos())->fd);
	(get_infos())->fd = 0;
	return (1);
}

int		reconfigure_term(ST *prev)
{
	struct termios new;

	if (tcgetattr(0, prev) == -1)
		return (-1);
	ft_memcpy(&new, prev, sizeof(new));
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &new) == -1)
		return (-1);
	return (0);
}
