#include "cub.h"

int	ft_map_valid_check(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (!ft_strchr("NEWS012 ", map[i][j]))
				return (0);
			if ((i == 0 || j == 0) && ft_strchr("NEWS02", map[i][j]))
				return (0);
			if ((map[i][j + 1] == '\0' && ft_strchr("NEWS02", map[i][j]))
				|| (map[i + 1] == NULL && (ft_strchr("NEWS02", map[i][j]))))
				return (0);
			if (ft_strchr("NEWS02", map[i][j]) && (map[i - 1][j] == ' ' || \
				map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || \
				map[i + 1][j] == ' ' || map[i - 1][j] == '\0' || \
				map[i][j - 1] == '\0' || map[i][j + 1] == '\0' || \
				map[i + 1][j] == '\0'))
				return (0);
		}
	}
	return (1);
}

void 	ft_parst_clear(t_pars *pars)
{
	pars->R = NULL;
	pars->NO = NULL;
	pars->SO = NULL;
	pars->WE = NULL;
	pars->EA = NULL;
	pars->S = NULL;
	pars->F = NULL;
	pars->C = NULL;
}

int 	ft_empty_field(t_pars *pars)
{
	return (pars->R == NULL || pars->NO == NULL || pars->SO == NULL || \
			pars->WE == NULL || pars->EA == NULL || pars->S == NULL || \
			pars->F == NULL || pars->C == NULL);
}

int	ft_pars_r(char *str, int *w, int *h)
{
	while (*str == ' ')
		str++;
	*w = ft_atoi_ud(str);
	while (*str != ' ')
		str++;
	*h = ft_atoi_ud(++str);
	if (*w < 0 || *h < 0)
		return (0);
	return (1);
}

int	ft_pars_let(t_pars *pars, char *str)
{
	while (*str && ft_is_space(*str))
		str++;
	if (!ft_strncmp(str, "R ", 2))
		pars->R = str;
	else if (!ft_strncmp(str, "NO ", 3))
		pars->NO = str;
	else if (!ft_strncmp(str, "SO ", 3))
		pars->SO = str;
	else if (!ft_strncmp(str, "WE ", 3))
		pars->WE = str;
	else if (!ft_strncmp(str, "EA ", 3))
		pars->EA = str;
	else if (!ft_strncmp(str, "S ", 2))
		pars->S = str;
	else if (!ft_strncmp(str, "F ", 2))
		pars->F = str;
	else if (!ft_strncmp(str, "C ", 2))
		pars->C = str;
	else
		return (0);
	return (1);
}
