#include "get_next_line.h"

char		*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

int			ft_strlen(char const *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char		*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
