#include "cub.h"

void	pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (x * (win->bpp / 8) + y * win->line_l);
	*(int *)dst = color;
}

int	ft_is_space(int c)
{
	return (c == '\t' || c == ' ');
}

char	*ft_skip_space(char *str)
{
	int		len;

	while (ft_is_space(*str))
		str++;
	len = ft_strlen(str) - 1;
	while (len > 0 && ft_is_space(str[len]))
		str[len--] = '\0';
	return (str);
}

int	ft_atoi_ud(const char *str)
{
	long	res;
	long	res_prev;

	res = 0;
	while (*str && ft_is_space(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-' || !ft_isdigit(*str))
		return (-1);
	while (*str && ft_isdigit(*str))
	{
		res_prev = res;
		res = res * 10 + (*str++ - '0');
		if (res < res_prev)
			return (INT32_MAX);
	}
	if (res > INT32_MAX)
		return (INT32_MAX);
	return ((int)res);
}

char	ft_after_whitespace(char *str)
{
	while (ft_is_space(*str))
		str++;
	return (*str);
}
