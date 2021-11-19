#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;

	if (s1 == 0 || set == 0)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = (char *)s1 + ft_strlen(s1) - 1;
	if (end < s1)
		return (ft_strdup(""));
	while (ft_strchr(set, *end))
		end--;
	return (ft_substr(s1, 0, end - s1 + 1));
}
