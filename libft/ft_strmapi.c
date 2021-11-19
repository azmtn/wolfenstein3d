#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	res = NULL;
	if (s && f)
	{
		res = ft_strnew(ft_strlen(s));
		if (res)
		{
			i = 0;
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
