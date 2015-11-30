#include "libft.h"

int	ft_size_num(int	n)
{
	int	len;

	len = 0;
	while (n /= 10)
		len++;
	return (len); 
}

char	*ft_itoa(int n)
{
	int	len;
	char	*str;
	
	len = ft_size_num(n);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	str = (char *)malloc(len + 1);
	if (*str == NULL)
		return (NULL);
	str[--len] = n % 10 + '0';
	while (n /= 10)
		str[--len] = n % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);

}
