/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:12:15 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 19:27:49 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_selected(t_item *items)
{
	t_item *current;

	current = items;
	while (42)
	{
		if (current->selected)
		{
			ft_putstr(current->value);
			ft_putchar(' ');
		}
		if (current->next == items)
			break ;
		current = current->next;
	}
}

void		select_quit(t_select *select, BOOL serve)
{
	term_show_cursor(TRUE);
	term_clear();
	term_end();
	tcsetattr(0, TCSANOW, &(select->term));
	if (serve && select->nb_selected)
	{
		print_selected(select->items);
		ft_putchar('\n');
	}
	exit(0);
}
