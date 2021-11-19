#include "libft.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	long	res;
	long	res_prev;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (ft_isdigit(*str))
	{
		res_prev = res;
		res = res * 10 + (*str++ - '0');
		if (res < res_prev)
			return ((sign == 1) * -1);
	}
	return ((int)(res * sign));
}
