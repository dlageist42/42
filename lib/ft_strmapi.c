#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char *str;
	
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * i + 1);
		i = 0;
		while (s[i])
		{
			str[i] = f((unsigned int)i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
