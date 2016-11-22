/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_show_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:09:32 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:34:10 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_show_cursor(BOOL on)
{
	static char *sshow = NULL;
	static char *shide = NULL;

	if (!sshow)
	{
		sshow = tgetstr("ve", &sshow);
		shide = tgetstr("vi", &shide);
	}
	term_write((on) ? sshow : shide);
}
