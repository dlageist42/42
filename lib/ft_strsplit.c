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

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int	i;
	int	nb_word;
	char	*word;
	char	*nxt_word;

	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_word + 1))));
		return (NULL);
	i = 0;
	while ((nxt_word = ft_strchr(tok, c)))
	{
		if ((nxt_word - word) > 0)
			tab[i++] = ft_strsub(s, word - s, nxt_word - word);
		word = word_next + 1;
	}
	if ((word_next = ft_strchr(word, '\0')) - word > 0)
		tab[i++] = ft_strsub(s, word - s, nxt_word - word);
	return (tab);
}
