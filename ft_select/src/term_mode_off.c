/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode_off.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:31:47 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:33:55 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_mode_off(void)
{
	static char *str = NULL;

	if (!str)
		str = tgetstr("me", &str);
	term_write(str);
}
