

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fdfwin
{
	int			lin;
	int			col;
	int			o;
	int			p;
	int			**tab;
	int			**sign;
	void		*mlx;
	void		*win;
	double		x;
	double		y;
	double		div;
	double		frat1;
	double		frat2;
	int			color;

}				t_fdfwin;

void			freetab(int **tableau);
void			prepare(t_fdfwin *store, char *str);
void			parseh(t_fdfwin *store, int x, int y, int m);
void			posve(t_fdfwin *store, int x, int y, int m);
void			posho(t_fdfwin *store, int x, int y, int m);
void			parstab(t_fdfwin *store, char *str);
void			egalho(t_fdfwin *store);
void			moinsho(t_fdfwin *store, int x, int y, double o);
void			mmoinsho(t_fdfwin *store, int x, int y, double o);
void			pplusho(t_fdfwin *store, int x, int y, double o);
void			tmoinsho(t_fdfwin *store, int x, int y, double o);
void			tplusho(t_fdfwin *store, int x, int y, double o);
void			plusho(t_fdfwin *store, int x, int y, double o);
void			tparseho(t_fdfwin *store, int x, int y, double o);
void			dparseho(t_fdfwin *store, int x, int y, double o);
void			oparseho(t_fdfwin *store, int x, int y, double o);
void			tplusve(t_fdfwin *store, int x, int y, double o);
void			tmoinsve(t_fdfwin *store, int x, int y, double o);
void			tparseve(t_fdfwin *store, int x, int y, double o);
void			dparseve(t_fdfwin *store, int x, int y, double o);
void			oparseve(t_fdfwin *store, int x, int y, double o);
void			hoposparse(t_fdfwin *store, int x, int y, double o);
void			veposparse(t_fdfwin *store, int x, int y, double o);
void			honegparse(t_fdfwin *store, int x, int y, double o);
void			venegparse(t_fdfwin *store, int x, int y, double o);
void			pplusve(t_fdfwin *store, int x, int y, double o);
void			mmoinsve(t_fdfwin *store, int x, int y, double o);
void			plusve(t_fdfwin *store, int x, int y, double o);
void			moinsve(t_fdfwin *store, int x, int y, double o);
void			egalve(t_fdfwin *store);
void			decla(t_fdfwin *store);
void			reduc(t_fdfwin *store);
void			parsev(t_fdfwin *store, int x, int y, int m);

char			*readsujet(char *str);

int				main(int ac, char **av);
int				**createtab(int nblin, int nbcol);
int				numbpar(t_fdfwin *store, char *str, int i);
int				hoparse(t_fdfwin *store, int x, int y, int m);
int				veparse(t_fdfwin *store, int x, int y, int m);
int				check(t_fdfwin *store, char *str);
int				alp(t_fdfwin *store, char *str);
#endif
