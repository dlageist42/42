/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_goto_relative.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:34 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:33:44 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_goto_relative(int x, int y)
{
	static char *str = NULL;

	if (!str)
		str = tgetstr("cm", &str);
	term_write(tgoto(str, x, y));
}
