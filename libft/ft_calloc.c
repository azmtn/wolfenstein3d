#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	size *= count;
	res = malloc(size);
	if (res)
		ft_bzero(res, size);
	return (res);
}
