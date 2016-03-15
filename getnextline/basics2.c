#include "get_next_line.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char *start;

	if (s2 == NULL)
		return (s1);
	start = s1;
	s1 += ft_strlen(s1);
	while (*s2)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (start);
}

void		*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = c;
		i++;
	}
	return (s);
}

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if(!(mem = malloc(size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
