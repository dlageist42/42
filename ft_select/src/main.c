/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:13:27 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:02:31 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int ac, char **av)
{
	t_select	select;

	if (ac == 1)
		return (0);
	select_init(&select, av + 1);
	setup_term(&select.term);
	select.fd = term_start(ttyname(0));
	setup_signals(&select);
	handle_inputs(&select);
	return (0);
}
