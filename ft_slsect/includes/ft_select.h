/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 13:57:58 by aschafer          #+#    #+#             */
/*   Updated: 2016/04/04 15:05:36 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define LP t_lst_params
# define INF t_infos
# define ST struct termios
# define WHITE "\e[30m"
# define GREEN "\e[92m"
# define RED "\e[91m"
# define RESET "\e[39m"
# define GREEN_BACK "\e[102m"
# define RESET_BACK "\e[49m"
# define BLINK_MODE "\e[5m"
# define RESET_MODE "\e[0m"

# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <curses.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_infos		t_infos;
struct						s_infos
{
	int		height;
	int		width;
	int		curr_page;
	int		nb_pages;
	int		nb_params;
	int		nb_lines;
	int		nb_selected;
	int		col_size;
	int		valid_size;
	int		load_cap;
	int		search;
	int		print;
	int		error;
	int		err;
	int		fd;
	int		index;
	char	str_search[30];
};

typedef struct s_lst_params	t_lst_params;
struct						s_lst_params
{
	int		select;
	int		page;
	int		on;
	int		y;
	char	*value;
	LP		*prev;
	LP		*next;
};

typedef enum				e_enum
{
	LEFT_KEY = 4479771,
	RIGHT_KEY = 4414235,
	UP_KEY = 4283163,
	DOWN_KEY = 4348699,
	ESC_KEY = 27,
	SPACE_KEY = 32,
	DEL_KEY = 127,
	SUP_KEY = 2117294875,
	RET_KEY = 10,
	END_KEY = 4610843,
	TAB_KEY = 9,
	HOME_KEY = 4741915,
}							t_enum;

/*
**** TERMINAL
*/
ST							*get_prev();
int							reconfigure_term(ST *prev);
int							restaure_term(ST *prev);
void						enable_env();
void						disable_env();
/*
**** TERMCAPS
*/
void						ft_tputs(char *cap, int nb);
void						ft_putstr_color_fd(char *s, char *col,
								int fd, int res);
void						ft_putstr_times(char *str, int nb,
								char *col, int fd);
void						ft_goto(int x, int y);
/*
**** LISTES
*/

LP							**lst_get_first(void);
LP							*lst_get_last(LP **first);
LP							*lst_new(LP *prev, char *value);
void						lst_push(LP **first, char *value);
void						lst_get_curr_page(LP *first, INF *infos);
int							lst_get_size(LP **first);
int							lst_get_size_line(LP **first);
void						lst_move(LP **curr, LP **first, char *buf);
void						lst_del(LP **first, LP **curr);
void						lst_search(LP **curr, INF *infos);
void						lst_free(LP **first);

/*
**** INFOS
*/

INF							*get_infos(void);
void						fill_infos(void);

/*
**** PROG
*/
int							error(char *s1, char *s2);
void						load_params(char **argv);
void						set_params(LP *first, INF *infos);
void						print_params(LP *first);
void						start_signal_handling(void);
void						start_select(void);
void						signal_handler(int sig);
void						draw(INF *infos, LP *curr);
void						render_bar(INF *infos);
void						input_handler(LP **fst, INF *inf, LP **curr,
								char *buf);
void						exit_prog(void);

#endif
