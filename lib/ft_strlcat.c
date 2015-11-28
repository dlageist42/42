#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	size_t	len;
	int	srclen;

	i = 0;
	len = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (len > dstsize)
		return (dstsize + srclen);
	while ((i + len) < (dstsize - 1) && src[i])
	{
		dst[len + 1] = src[i];
		i++;
	}
	dst[len +i] = '\0';
	return (len + srclen);
}
