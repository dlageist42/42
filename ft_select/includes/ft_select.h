/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 20:35:13 by qle-bevi          #+#    #+#             */
/*   Updated: 2016/03/31 20:38:20 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "keys.h"
# include "libft.h"
# include <curses.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <unistd.h>
# include <sys/stat.h>
# define MODES {S_IFIFO,S_IFCHR,S_IFDIR,S_IFBLK,S_IFREG,S_IFLNK,S_IFSOCK}
# define COLORS {"\e[32","\e[33m","\e[34m","\e[33m","\e[37m","\e[35m","\e[32m"}
# define EOC "\e[0m"
# define CGREY "\e[48;5;234m"
# define CWHITE "\e[48;5;234m"
# define CRED "\e[38;5;196m"

typedef struct s_item	t_item;
typedef struct s_search	t_search;
typedef struct s_select	t_select;

typedef enum	e_filetype
{
	FIFO,
	CHR,
	DIR,
	BLK,
	REG,
	LNK,
	SOCK,
	WHT
}				t_filetype;

typedef enum	e_direction
{
	UP = K_UP,
	DOWN = K_DOWN,
	RIGHT = K_RIGHT,
	LEFT = K_LEFT
}				t_direction;

struct			s_item
{
	int			x;
	int			y;
	int			page;
	char		*value;
	t_filetype	type;
	BOOL		selected;
	t_item		*prev;
	t_item		*next;
};

struct			s_search
{
	char		buffer[30];
	int			i;
	t_select	*select;
};

struct			s_select
{
	BOOL			active;
	t_item			*items;
	t_item			*current;
	struct winsize	size;
	struct termios	term;
	t_search		search;
	int				nb_selected;
	int				total;
	int				page;
	int				fd;
	int				nb_pages;
	int				items_width;

};

void			setup_term(struct termios *term);

void			select_init(t_select *select, char **av);
void			select_del(t_select *select);
void			select_update(t_select *select);
void			select_render(t_select *select);
void			select_render_item(t_select *select, t_item *item);
void			select_render_bar(t_select *select);
void			select_quit(t_select *select, BOOL serve);
void			select_move(t_select *select, t_direction direction);
void			select_toggle(t_select *select);

void			term_go_home();
void			term_clear();
void			term_clear_down();
void			term_goto_relative(int x, int y);
void			term_mode_rv();
void			term_mode_off();
void			term_underline(BOOL on);
void			term_show_cursor(BOOL on);
void			term_write(char *str);
int				term_start(char *tty);
void			term_end();

void			search_add(t_search *search, char c);
void			search_render(t_search *search);
void			search_remove(t_search *search);
void			search_reset(t_search *search);
void			search_find(t_search *search);

void			handle_inputs();

void			draw_bar(char *color, int width);
void			setup_signals(t_select *select);
#endif
