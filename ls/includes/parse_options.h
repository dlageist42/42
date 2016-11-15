

#ifndef PARSE_OPTIONS_H
# define PARSE_OPTIONS_H
# include "libft.h"
# define OPTS char
# define VALID_OPTS "alrRSt"
# define OPT(mask, opt) has_option(mask, opt)

int  parse_options(int ac, char **av, OPTS *opts, void (*f)(char c));
BOOL	has_option(OPTS options, char c);
#endif
