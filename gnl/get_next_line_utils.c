#include "get_next_line.h"

char	*ft_strnew1(size_t size)
{
	return ((char *)malloc(sizeof(char) * (size + 1)));
}

size_t	ft_strlen1(const char *s)
{
	const char	*str;

	str = s;
	if (!str)
		return (0);
	while (*str)
		str++;
	return (str - s);
}

char	*ft_strchr1(const char *s, int c)
{
	char	*p;
	char	ch;

	p = (char *)s;
	ch = (char)c;
	while (1)
	{
		if (*p == ch)
		{
			*p = '\0';
			return (++p);
		}
		if (*p++ == 0)
			return (NULL);
	}
}

char	*ft_strjoin1(const char *s1, const char *s2)
{
	char	*res;
	char	*r;
	char	*tmp;

	tmp = (char *)s1;
	res = ft_strnew1(ft_strlen1(s1) + ft_strlen1(s2));
	if (res)
	{
		r = res;
		if (s1)
			while (*s1)
				*r++ = *s1++;
		if (s2)
			while (*s2)
				*r++ = *s2++;
		*r = '\0';
	}
	free(tmp);
	return (res);
}
