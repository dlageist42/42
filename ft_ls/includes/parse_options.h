/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:14:41 by dlageist          #+#    #+#             */
/*   Updated: 2016/11/18 13:14:42 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_OPTIONS_H
# define PARSE_OPTIONS_H
# include "libft.h"
# define OPTS char
# define VALID_OPTS "alrRSt"
# define OPT(mask, opt) has_option(mask, opt)

int		parse_options(int ac, char **av, OPTS *opts, void (*f)(char c));
BOOL	has_option(OPTS options, char c);
#endif
