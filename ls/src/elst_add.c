#include "ft_ls.h"

t_elst *elst_add(t_elst **begin, t_elst *last, t_elst *new)
{
  if (!*begin)
    return (*begin = new);
  return (last->next = new);
}
