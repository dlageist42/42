#include "ft_ls.h"

t_elst *elst_pop(t_elst **begin)
{
  t_elst *elem;

  if (!*begin)
    return (NULL);
  elem = *begin;
  *begin = elem->next;
  elem->next = NULL;
  return (elem);
}
