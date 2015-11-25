#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return (&*str);
		str++;
	}
	return (NULL);
}

int	main()
{
	char a = '\0';
	char *b = "blablebloublabli";
	char *ret;

	ret = ft_strchr(b, a);
	printf("%s", ret);
	return (0);
}
