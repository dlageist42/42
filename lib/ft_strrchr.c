#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	int i;

	str = (char *)s;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (unsigned char)c)
			return(&str[i]);
		i--;
	}
	return (NULL);
}
