#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	str = (char *)malloc(size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, (int)'\0', size);
	return (str);
}
