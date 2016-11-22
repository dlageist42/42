/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:28 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:33:19 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_clear(void)
{
	static char *str = NULL;

	if (!str)
		str = tgetstr("cl", &str);
	term_write(str);
}
