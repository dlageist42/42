#include "libft.h"

int	strcmp(const char *s1, const char *s2)
{
	size_t	i;
	char	*string1;
	char	*string2;

	i = 0;
	string1 = (char *)s1;
	string2 = (char *)s2;
	if ((string1[0] = '\0') && (string2[0] == '\0'))
		return(0);
	while(string1[i] == string2[i])
	{
		i++;
		if((string1[i] == '\0') && (string2[i] == '\0'))
			return(0);
	}
	return(string1[i] - string2[i]);
}
