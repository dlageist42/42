/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:27:58 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/16 12:55:14 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_OPTIONS_H
# define PARSE_OPTIONS_H
# include "../lib/libft/libft.h"
# define OPTS char
# define VALID_OPTS "alrRSt"
# define OPT(mask, opt) has_option(mask, opt)

typedef	enum {
		TRUE  = (1 == 1),
		FALSE = (1 == 0),
}		BOOL;

int		parse_options(int ac, char **av, OPTS *opts, void (*f)(char c));
BOOL	has_option(OPTS options, char c);
#endif
