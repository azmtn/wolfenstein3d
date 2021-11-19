#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	unsigned char	uc;

	dst = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- != 0)
		*dst++ = uc;
	return (s);
}
