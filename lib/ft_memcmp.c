#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	unsigned char	string1;
	unsigned char	string2;

	i = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	if (string1 == NULL && string2 == NULL)
		return (0);
	while (i <= n && string1[i] == string2[i])
	{
		i++;
		if(i == n || (string1[i] == '\0' && string2[i] == '\0')
			return (0);
	}
	return (string1[i] - string2[i]);
}
