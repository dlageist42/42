/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode_rv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:27:37 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:34:04 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_mode_rv(void)
{
	static char *str = NULL;

	if (!str)
		str = tgetstr("mr", &str);
	term_write(str);
}
