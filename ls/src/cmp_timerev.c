#include "ft_ls.h"

BOOL cmp_timerev(t_elst *a, t_elst *b)
{
  return (a->lmtime < b->lmtime);
}
