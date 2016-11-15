#include <sys/xattr.h>
#include <unistd.h>
#include "ft_ls.h"

static char buffer[500] = {0};

static void add_permissions(t_type type, mode_t mode, BOOL hxattrs)
{
  static char cletters[] = "pcdb-ls-";

  buffer[0] = cletters[type];
  buffer[1] = mode & S_IRUSR ? 'r' : '-';
  buffer[2] = mode & S_IWUSR ? 'w' : '-';
  if (mode & S_ISUID)
    buffer[3] = mode & S_IXUSR ? 's' : 'S';
  else
    buffer[3] = mode & S_IXUSR ? 'x' : '-';
  buffer[4] = mode & S_IRGRP ? 'r' : '-';
  buffer[5] = mode & S_IWGRP ? 'w' : '-';
  if (mode & S_ISGID)
    buffer[6] = mode & S_IXGRP ? 's' : 'S';
  else
    buffer[6] = mode & S_IXGRP ? 'x' : '-';
  buffer[7] = mode & S_IROTH ? 'r' : '-';
  buffer[8] = mode & S_IWOTH ? 'w' : '-';
  if (mode & S_ISVTX)
    buffer[9] = mode & S_IXOTH ? 't' : 'T';
  else
    buffer[9] = mode & S_IXOTH ? 'x' : '-';
  buffer[10] = hxattrs ? '@' : ' ';
}

static void pad(char **head, char *str, int pad, BOOL right)
{
  int i;

  i = 0;
  if (!right)
    while (i < pad)
    {
      **head = ' ';
      ++i;
      *head += 1;
    }
  while (*str)
  {
    **head = *str;
    *head += 1;
    ++str;
  }
  if (right)
    while (i < pad)
    {
      **head = ' ';
      ++i;
      *head += 1;
    }
}

void print_entry_long(t_elst *entry)
{
  t_elstinfos *infos;
  char *head;

  infos = &g_elstinfos;
  head = buffer + 11;
  add_permissions(entry->type, entry->mode, entry->hxattrs);
  pad(&head, entry->nlink,
     infos->max_lnks - ft_strlen(entry->nlink) + 1, FALSE);
  *(head++) = ' ';
  pad(&head, entry->owner,
     infos->max_owner - ft_strlen(entry->owner) + 1, TRUE);
  *(head++) = ' ';
  pad(&head, entry->group,
     infos->max_group - ft_strlen(entry->group) + 1, TRUE);
  pad(&head, entry->strsize,
     infos->max_size - ft_strlen(entry->strsize) + 1, FALSE);
  *(head++) = ' ';
  ft_strcat(head, entry->strtime);
  ft_strcat(head, " ");
  write(1, buffer, ft_strlen(buffer));
  print_entry(entry);
  ft_strclr(buffer);
}
