/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_clear_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:24 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:33:06 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		term_clear_down(void)
{
	static char *str = NULL;

	if (!str)
		str = tgetstr("cd", &str);
	term_write(str);
}
