#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		len;

	odst = dst;
	osrc = src;
	n = size;
	while (n-- != 0 && *dst != '\0')
		dst++;
	len = dst - odst;
	n = size - len;
	if (n-- == 0)
		return (len + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (len + (src - osrc));
}
