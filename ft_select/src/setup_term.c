/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:20 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:32:49 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	setup_term(struct termios *term)
{
	char			*term_name;
	struct termios	new;

	if ((term_name = getenv("TERM")) == NULL)
		return (ft_errexit(1, "TERM var not set. Need it !"));
	if (tgetent(NULL, term_name) == ERR)
		return (ft_errexit(1, "Unable to load term caps !"));
	if (tcgetattr(0, term) == -1)
		return (ft_errexit(1, "Unable to load term attributes !"));
	ft_memcpy(&new, term, sizeof(struct termios));
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &new);
}
