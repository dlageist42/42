
#include "ft_ls.h"

static BOOL output = FALSE;
static BOOL (*sort_cmp)(t_elst *, t_elst *) = NULL;
static void (*print_entries)(t_elst **) = NULL;
static t_elst *entries = NULL;

BOOL g_need_size = FALSE;
BOOL g_long_display = FALSE;
BOOL g_get_all = FALSE;
t_elstinfos g_elstinfos;
t_elst *g_dirs = NULL;

static void on_illegal_option(char c)
{
  ft_putstr_fd("ft_ls: illegal option -- ", 2);
  ft_putchar_fd(c, 2);
  ft_putchar_fd('\n', 2);
  ft_errexit(USAGE);
}

static void init(OPTS options)
{
  g_need_size = OPT(options, 'S');
  if (OPT(options, 'S') && OPT(options, 'r'))
    sort_cmp = cmp_sizerev;
  else if (OPT(options, 'S'))
    sort_cmp = cmp_size;
  else if (OPT(options, 't') && OPT(options, 'r'))
    sort_cmp = cmp_timerev;
  else if (OPT(options, 't'))
    sort_cmp = cmp_time;
  else if (OPT(options, 'r'))
    sort_cmp = cmp_alpharev;
  else
    sort_cmp = cmp_alpha;
  print_entries = OPT(options, 'R') ? print_entries_rec : print_entries_simple;
  if (OPT(options, 'l'))
  {
      g_long_display = TRUE;
      set_print_entry_func(print_entry_long);
  }
  g_get_all = OPT(options, 'a');
}

static void load_entries(int ac, char **av)
{
  int i;
  t_elst *current;
  t_elst *d_last;
  t_elst *f_last;

  if (!ac)
    return ((void)elst_add(&g_dirs, NULL, new_entry(ft_strdup("."), TRUE)));
  i = 0;
  d_last = NULL;
  f_last = NULL;
  while (i < ac)
  {
    if ((current = new_entry(ft_strdup(av[i++]), TRUE)))
    {
      if (current->type == EDIR)
        d_last = elst_add(&g_dirs, d_last, current);
      else
        f_last = elst_add(&entries, f_last, current);
    }
  }
  elst_sort(&g_dirs, sort_cmp);
  elst_sort(&entries, sort_cmp);
}

static void do_listing(BOOL all)
{
  t_elst *current;

  if (entries)
  {
    output = TRUE;
    print_entries(&entries);
  }
  while ((current = elst_pop(&g_dirs)))
  {
    if (load_dir(current->path, &entries, all))
    {
      elst_sort(&entries, sort_cmp);
      if (output)
      {
        ft_putstr(current->path);
        ft_putendl(":");
      }
      output = TRUE;
      print_entries(&entries);
    }
    elst_del(current);
  }
}

int						main(int ac, char **av)
{
	int i;
	OPTS options;

  options = 0;
	i = parse_options(ac, av, &options, on_illegal_option);
	init(options);
  load_entries(ac - i, av + i);
  do_listing(OPT(options, 'a'));
	return (EXIT_SUCCESS);
}
