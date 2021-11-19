#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(s1) + 1;
	copy = (char *)ft_calloc(size, sizeof(char));
	if (copy)
		ft_memcpy(copy, s1, size);
	return (copy);
}
