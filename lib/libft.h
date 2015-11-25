#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memccpy(void* dest, const void* src, int c, size_t n);
void	*ft_memcpy(void *dest, const void* src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memchr(const void *S, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_isdigit(int c);
int	ft_isalpha(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);

int	ft_toupper(int c);
int	ft_tolower(int c);

void	ft_bzero(void *s, size_t n);
