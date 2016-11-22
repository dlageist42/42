/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_underline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:55:17 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:34:15 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_underline(BOOL on)
{
	static char *son = NULL;
	static char *soff = NULL;

	if (!son)
	{
		son = tgetstr("us", &son);
		soff = tgetstr("ue", &soff);
	}
	term_write((on) ? son : soff);
}
