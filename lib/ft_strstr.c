#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (little[0] == '\0')
		return((char *)big);
	while (big[i])
	{
		k = i;
		j = 0;
		while (big[k] == little[j])
		{
			k++;
			j++;
			if (little[j] == '\0')
				return((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
