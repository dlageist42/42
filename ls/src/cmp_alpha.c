#include "ft_ls.h"

BOOL cmp_alpha(t_elst *a, t_elst *b)
{
  return (ft_strcmp(a->name, b->name) <= 0);
}
