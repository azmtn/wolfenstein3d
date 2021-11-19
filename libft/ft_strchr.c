#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	ch;

	p = (char *)s;
	ch = (char)c;
	while (1)
	{
		if (*p == ch)
			return (p);
		if (*p++ == 0)
			return (NULL);
	}
}
