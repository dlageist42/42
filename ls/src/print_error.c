#include <stdio.h>
#include "ft_ls.h"

void    print_error(char *str)
{
  ft_putstr_fd("ft_ls: ", 2);
  perror(str);
}
