/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:44:44 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 13:53:46 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_param(int one, int two, int fd)
{
	char *str;
	char *str2;

	str = ft_itoa(one);
	str2 = ft_itoa(two);
	ft_putstr_color_fd(str, WHITE, fd, 1);
	ft_putstr_color_fd("/", WHITE, fd, 1);
	ft_putstr_color_fd(str2, WHITE, fd, 1);
	ft_memdel((void **)&str);
	ft_memdel((void **)&str2);
}

void		render_bar(INF *infos)
{
	ft_putstr_times(" ", infos->width - 1, GREEN_BACK, infos->fd);
	ft_goto(3, infos->height);
	print_param(infos->nb_selected, infos->nb_params, infos->fd);
	ft_putstr_color_fd(" Selected ", WHITE, infos->fd, 1);
	ft_putstr_color_fd(infos->nb_selected ? "❤️" : "💔", WHITE, infos->fd, 1);
	ft_putstr_color_fd(infos->search ? "   🔎  " : "", WHITE, infos->fd, 1);
	ft_putstr_color_fd(infos->search ? infos->str_search : "", WHITE,
	infos->fd, 1);
	ft_goto(infos->width - 7, infos->height);
	print_param(infos->curr_page, infos->nb_pages, infos->fd);
	ft_putstr_fd(RESET_BACK, infos->fd);
}
