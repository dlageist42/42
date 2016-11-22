/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_go_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:31 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:33:38 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_go_home(void)
{
	static char *str = NULL;

	if (!str)
		str = tgetstr("ho", &str);
	term_write(str);
}
