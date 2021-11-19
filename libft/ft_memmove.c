#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!(len == 0 || d == s))
	{
		if (d < s)
		{
			while (len-- != 0)
				*d++ = *s++;
		}
		else
		{
			d += len;
			s += len;
			while (len-- != 0)
				*--d = *--s;
		}
	}
	return (dst);
}
