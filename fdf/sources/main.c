/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpernes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:40:00 by fpernes           #+#    #+#             */
/*   Updated: 2016/11/19 18:58:02 by fpernes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	prepare(t_fdfwin *store, char *str)
{
	int i;
	int o;

	i = 0;
	o = 0;
	while (str[i] != '\n')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n'))
			o++;
		i++;
	}
	store->col = o;
	o = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			o++;
		i++;
	}
	if (str[i] == '\0' && str[i - 1] != '\n')
		o--;
	store->lin = o;
}

int		**createtab(int nblin, int nbcol)
{
	int			**tableau;
	int			*tableau2;
	int			i;

	tableau = (int **)malloc(sizeof(int*) * nblin);
	tableau2 = (int *)malloc(sizeof(int) * nbcol * nblin);
	i = 0;
	while (i < nblin)
	{
		tableau[i] = &tableau2[i * nbcol];
		i++;
	}
	return (tableau);
}

char	*readsujet(char *str)
{
	int			fd;
	int			len;
	char		*new;

	if (!(new = (char *)malloc(sizeof(char) * 5000000)))
		return (NULL);
	if (!(fd = open(str, O_RDONLY)))
		return (NULL);
	if (fd == -1)
		return (NULL);
	len = read(fd, new, 5000000);
	if (len == -1)
		return (NULL);
	new[len] = '\n';
	new[++len] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (new);
}

int		escape(int keycode, t_fdfwin *store)
{
	if (keycode == 53)
	{
		mlx_destroy_window(store->mlx, store->win);
		freetab(store->tab);
		freetab(store->sign);
		exit(0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	static	t_fdfwin	store;
	char				*str;
	int					x;
	int					y;
	int					m;

	if (ac != 2 || !(str = readsujet(av[1])))
	{
		write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		return (-1);
	}
	prepare(&store, str);
	if (check(&store, str) == -1)
	{
		write(1, "Found wrong line length. Exiting.\n", 35);
		return (-1);
	}
	decla(&store);
	parstab(&store, str);
	parseh(&store, x, y, m);
	printf("%d\n", store->lin);
	printf("%d\n"), store->col);
	mlx_key_hook(store.win, escape, &store);
	mlx_loop(store.mlx);
}
