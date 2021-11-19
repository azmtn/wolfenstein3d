#include "libft.h"

static int	ft_count_words(char const **s, char c)
{
	int			words;
	const char	*p;

	words = 0;
	while (**s && **s == c)
		(*s)++;
	p = *s;
	while (*p)
	{
		while (*p && *p != c)
			p++;
		words++;
		while (*p && *p == c)
			p++;
	}
	return (words);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s++ != c)
		i++;
	return (i);
}

static void	ft_next_pointer(char const **s, char c)
{
	*s = ft_strchr(*s, c);
	while (*s && **s && **s == c)
		(*s)++;
}

static char	**ft_free_words(char **words, size_t i)
{
	while (i--)
		free(words[i]);
	free(*words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		w_count;
	int		i;

	if (s == 0)
		return (NULL);
	w_count = ft_count_words(&s, c);
	words = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (words)
	{
		i = 0;
		while (i < w_count)
		{
			words[i] = ft_strnew(ft_word_len(s, c));
			if (words[i])
				ft_strlcpy(words[i], s, ft_word_len(s, c) + 1);
			else
				return (ft_free_words(words, i));
			ft_next_pointer(&s, c);
			i++;
		}
		words[i] = NULL;
	}
	return (words);
}
