#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		uc;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	uc = (unsigned char)c;
	while (n-- != 0)
	{
		*d = *s;
		if (*d == uc)
			return (++d);
		d++;
		s++;
	}
	return (0);
}
