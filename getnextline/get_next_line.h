#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFF_SIZE 32

int			get_next_line(int const fd, char **line);
char		*ft_strchr(char *str, int c);
int			ft_strlen(char const *str);
char		*ft_strdup(char *str);
char		*ft_strnew(size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memalloc(size_t size);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
