#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *start;

	start = dest;
	dest += strlen(dest);
	while (*src && n-- > 0)
		*(dest++) = *(src++);
	*dest = '\0';
	return (start);
}
