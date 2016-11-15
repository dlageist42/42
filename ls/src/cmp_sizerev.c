#include "ft_ls.h"

BOOL cmp_sizerev(t_elst *a, t_elst *b)
{
  return (a->size <= b->size);
}
