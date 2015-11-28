#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int	i;
	int	j;
	int	k;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(s);
	if ((s[i] != ' ' || s[i] != '\n' || s[i] == '\t')
	   	&& (s[k] != ' ' || s[k] != '\n' || s[k] != '\t'))
		return ((char *)s);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[k] == ' ' || s[k] == '\n' || s[j] == '\t')
		k--;
	while (i <= k)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	return (str);
}
