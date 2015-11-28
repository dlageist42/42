#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t i;
	char *str;
	
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * (i + 1));
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
