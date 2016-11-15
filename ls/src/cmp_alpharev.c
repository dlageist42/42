#include "ft_ls.h"

BOOL cmp_alpharev(t_elst *a, t_elst *b)
{
  return (ft_strcmp(a->name, b->name) >= 0);
}
