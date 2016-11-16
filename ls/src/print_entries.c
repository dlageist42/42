/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:13:59 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/16 12:00:49 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void (*g_print)(t_elst *) = print_entry;

static void		handle_long_display(t_elst *list)
{
	t_elstinfos	*infos;
	t_elst		*current;
	int			len;

	infos = &g_elstinfos;
	ft_bzero(infos, sizeof(t_elstinfos));
	current = list;
	while (current)
	{
		infos->total += current->blocks;
		if ((len = ft_strlen(current->nlink)) > infos->max_lnks)
			infos->max_lnks = len;
		if ((len = ft_strlen(current->owner)) > infos->max_owner)
			infos->max_owner = len;
		if ((len = ft_strlen(current->group)) > infos->max_group)
			infos->max_group = len;
		if ((len = ft_strlen(current->strsize)) > infos->max_size)
			infos->max_size = len;
		current = current->next;
	}
	if (list && list->next)
	{
		print_total(infos);
	}
}

void			set_print_entry_func(void (*func)(t_elst *))
{
	g_print = func;
}

void			print_entries_simple(t_elst **entries)
{
	t_elst *current;

	if (g_long_display)
		handle_long_display(*entries);
	while ((current = elst_pop(entries)))
	{
		g_print(current);
		elst_del(current);
	}
	if (g_dirs)
		ft_putchar('\n');
}

void			print_entries_rec(t_elst **entries)
{
	t_elst *current;
	t_elst *dirs;
	t_elst *last;

	dirs = NULL;
	last = NULL;
	if (g_long_display)
		handle_long_display(*entries);
	while ((current = elst_pop(entries)))
	{
		g_print(current);
		if (current->type == EDIR && (!g_get_all || !ISDOTDIR(current->name)))
			last = elst_add(&dirs, last, current);
		else
			elst_del(current);
	}
	if (last)
	{
		last->next = g_dirs;
		g_dirs = dirs;
	}
	if (g_dirs)
		ft_putchar('\n');
}
