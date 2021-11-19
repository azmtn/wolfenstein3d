#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = (n < 0) + 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	str = ft_strnew(ft_numlen(n));
	if (!str)
		return (NULL);
	str += ft_numlen(n);
	*str = '\0';
	while (1)
	{
		*--str = '0' + (n % 10) * sign;
		n /= 10;
		if (n == 0)
		{
			if (sign == -1)
				*--str = '-';
			return (str);
		}
	}
}
