#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	uc;

	p = (char *)s + ft_strlen(s);
	uc = (char)c;
	while (p >= s && *p != uc)
		p--;
	if (p >= s)
		return (p);
	return (NULL);
}
