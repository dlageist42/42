#include "libft.h"

char	*ft_strdup(const char *s)
{
	int	i;
	int	j;
	char	*dup;
	i = ft_strlen(s);
	j = 0;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == '\0')
		return (NULL);
	while (j < i)
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
