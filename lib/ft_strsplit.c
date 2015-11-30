#include "libft.h"

int	ft_count_word(char const *s, char c)
{
	char	*str;
	int	count;
	int	i;

	str = (char *)s;
	count = 0;
	i = 0;
	while (*str)
	{
		if (i == 1 && *str == c)
			i = 0;
		if (i == 0 && *str != c)
		{
			i = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int	ft_wordlen(char	*s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		while(*s != c && *s != '\0')
		{
			len++;
			s++;
		}
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int	i;
	int	nb_word;
	
	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_word))))
		return (NULL);
	i = 0;
	while ((nb_word--))
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub(s, 0, ft_wordlen((char *)s, c));
		s += ft_wordlen;
		i++;
	}
	return (tab);
}
