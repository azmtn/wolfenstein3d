#include "get_next_line.h"

static char	*ft_rem_checker(char **line, char **remainder)
{
	char	*p;
	char	*tmp;

	if (!*remainder)
		*line = ft_strjoin1(NULL, NULL);
	else
	{
		p = ft_strchr1(*remainder, '\n');
		if (p)
		{
			*line = ft_strjoin1(NULL, *remainder);
			tmp = *remainder;
			*remainder = ft_strjoin1(NULL, p);
			free(tmp);
			return (p);
		}
		*line = ft_strjoin1(*remainder, NULL);
		*remainder = NULL;
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder = NULL;
	char		buf[BUFFER_SIZE + 1];
	char		*p;
	int			len;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) != 0)
		return (-1);
	p = ft_rem_checker(line, &remainder);
	if (!*line || (p && !remainder))
		return (-1);
	while (!p)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (!len)
			break ;
		buf[len] = '\0';
		p = ft_strchr1(buf, '\n');
		if (p)
			remainder = ft_strjoin1(NULL, p);
		*line = ft_strjoin1(*line, buf);
		if (!(*line) || (p && !remainder))
			return (-1);
	}
	return (p != 0);
}
