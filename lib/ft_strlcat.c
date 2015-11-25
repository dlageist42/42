#include "libft.h"
#include <stdio.h>
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	len;
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

int	main()
{
	char *src = "salut";
	char *dst = "ca va";
	int i;

	i = 5;
	printf("%s", ft_strlcat(dst, src, i));
	return (0);
}
