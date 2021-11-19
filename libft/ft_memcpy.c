#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!(n == 0 || d == s))
	{
		while (n-- != 0)
			*d++ = *s++;
	}
	return (dst);
}
