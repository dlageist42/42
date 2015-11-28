#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	x;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*(s1 + i) = *(s2 + i);
		if (*(s1 + 1) == x)
		{
			i += 1;
			return ((char *)dest + i);
		}
		i++;
	}
	return (NULL);
}
