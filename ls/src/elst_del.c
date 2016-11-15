#include "ft_ls.h"

void elst_del(t_elst *entry)
{
  free(entry->path);
  if (g_long_display)
  {
    free(entry->nlink);
    free(entry->strtime);
    free(entry->owner);
    free(entry->group);
  }
  if (entry->strsize)
    free(entry->strsize);
  free(entry);
}
