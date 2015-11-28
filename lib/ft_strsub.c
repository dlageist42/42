#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (*str == '\0')
		return (NULL);
	i = 0;
	while (len-- > 0)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
