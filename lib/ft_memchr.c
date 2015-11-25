#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	unsigned char	temp;

	temp = (unsigned char *)s
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return ((void *)temp + i);
		i++;
	}
	return (NULL);
}

