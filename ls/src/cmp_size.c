#include "ft_ls.h"

BOOL cmp_size(t_elst *a, t_elst *b)
{
  return (a->size >= b->size);
}
