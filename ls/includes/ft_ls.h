/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:06:57 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/16 12:27:50 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "parse_options.h"
# define ILLEGAL_OPTION "illegal option -- "
# define USAGE "usage: ft_ls [-alrRSt] [file ...]"
# define SHLDPRYR(ctim, tim) (ctim - tim > 15552000 || ctim - tim < -1)
# define MODES {S_IFIFO, S_IFCHR, S_IFDIR, S_IFBLK, S_IFREG, S_IFLNK, S_IFSOCK};
# define CDEF "\033[00m"
# define COLORS {"\033[33m", NULL, "\033[34m", "\033[33m", NULL, "\033[35m","\033[36m", NULL}
# define STAT struct stat
# define DIRE struct dirent
# define ISDOTDIR(name) (ft_strequ(name, ".") || ft_strequ(name, ".."))

/*
**	APP
*/

typedef struct			s_flags
{
	BOOL				all;
	BOOL				list;
	BOOL				rev;
	BOOL				rec;
	BOOL				time;
}						t_flags;

typedef enum			e_type
{
	EFIFO,
	ECHR,
	EDIR,
	EBLK,
	EREG,
	ELNK,
	ESOCK,
	EWHT
}						t_type;

typedef struct s_elst	t_elst;

struct					s_elst
{
	t_type				type;
	char				*name;
	char				*path;
	char				*owner;
	char				*group;
	char				*nlink;
	char				*strtime;
	char				*strsize;
	BOOL				hxattrs;
	size_t				size;
	time_t				lmtime;
	blkcnt_t			blocks;
	mode_t				mode;
	t_elst				*next;
};

typedef struct			s_elstinfos
{
	blkcnt_t			total;
	int					max_lnks;
	int					max_owner;
	int					max_group;
	int					max_size;
}						t_elstinfos;

extern					t_elstinfos g_elstinfos;
extern					BOOL g_need_size;
extern					BOOL g_long_display;
extern					BOOL g_get_all;
extern					t_elst *g_dirs;

t_elst					*elst_pop(t_elst **begin);
t_elst					*elst_add(t_elst **begin, t_elst *last, t_elst *entry);
BOOL					cmp_alpha(t_elst *a, t_elst *b);
BOOL					cmp_alpharev(t_elst *a, t_elst *b);
BOOL					cmp_size(t_elst *a, t_elst *b);
BOOL					cmp_sizerev(t_elst *a, t_elst *b);
BOOL					cmp_time(t_elst *a, t_elst *b);
BOOL					cmp_timerev(t_elst *a, t_elst *b);
void					elst_sort(t_elst **a, BOOL (*b)(t_elst *a, t_elst *b));
void					elst_del(t_elst *elem);

void					print_entry(t_elst *entry);
void					print_entry_long(t_elst *entry);
void					print_entries_simple(t_elst **entries);
void					print_entries_rec(t_elst **entries);
void					set_print_entry_func(void (*func)(t_elst *));
void					print_total(t_elstinfos *infos);
t_elst					*new_entry(char *path, BOOL path_is_name);
BOOL					load_dir(char *path, t_elst **entries, BOOL all);
void					print_error(char *str);

#endif
