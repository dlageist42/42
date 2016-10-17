/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlageist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:36:56 by dlageist          #+#    #+#             */
/*   Updated: 2016/10/17 13:36:58 by dlageist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_start_recursive(t_lsdir *lsdir, t_lsoption *option)
{
	DIR		*dir;

	if (!option->optiona)
		option->hidden = 1;
	if (lsdir->name[0] != '.' || option->optiona)
	{
		ft_putchar('\n');
		option->hidden = 0;
		ft_putstr(lsdir->path);
		ft_putendl(":");
	}
	dir = opendir(lsdir->path);
	if (!lsdir->next && lsdir)
		free(lsdir->stat);
	if (dir != 0)
		ft_startls(dir, option, lsdir->path, NULL);
	else
	{
		ft_putstr(TITLE);
		ft_putstr(": ");
		perror(lsdir->name);
	}
	if (dir != NULL)
		closedir(dir);
}

void	ls_recursiveon(t_lsdir *lsdir, t_lsoption *option)
{
	if (!option->optionr)
	{
		while (lsdir->previous)
			lsdir = lsdir->previous;
	}
	else
	{
		while (lsdir && lsdir->next)
			lsdir = lsdir->next;
	}
	while (lsdir)
	{
		if (S_ISDIR(lsdir->stat->st_mode) && ft_strcmp(lsdir->name, ".")
				&& ft_strcmp(lsdir->name, ".."))
			ft_start_recursive(lsdir, option);
		if (!option->optionr)
			lsdir = lsdir->next;
		else
			lsdir = lsdir->previous;
	}
}

char	**ft_argsortreverse(char **argv, int start, int end)
{
	int			left;
	int			right;
	const char	*pivot;

	left = start - 1;
	right = end + 1;
	pivot = argv[start];
	if (start >= end)
		return (argv);
	while (left < right)
	{
		right--;
		while (ft_strcmp(argv[right], pivot) < 0)
			right--;
		left++;
		while (ft_strcmp(argv[left], pivot) > 0)
			left++;
		if (left < right)
			ls_swapstr(&argv[left], &argv[right]);
	}
	argv = ft_argsortreverse(argv, start, right);
	argv = ft_argsortreverse(argv, right + 1, end);
	return (argv);
}

void	ls_addpath(t_lsdir *new, char *name, char *path)
{
	char *pathfile;

	if (path)
	{
		if (ft_strcmp(path, "/"))
			pathfile = ft_strjoin(path, ft_strjoin("/", name));
		else
			pathfile = ft_strjoin(path, name);
		new->path = pathfile;
		lstat(pathfile, new->stat);
	}
	else
	{
		lstat(name, new->stat);
		new->path = ft_strjoin("./", name);
	}
}
