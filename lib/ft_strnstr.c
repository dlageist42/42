#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && n-- > 0)
	{
		k = i;
		j = 0;
		while(big[k] == little[j])
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

int	main()
{
	char *big = "kokoasdfghjkl";
	char *little = "sdf";
	int n = 2;
	printf("%s", ft_strnstr(big, little, n));
	return (0);
}
