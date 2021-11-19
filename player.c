#include "cub.h"

void	ft_plr_NS(char idn, t_plr *plr)
{
	if (idn == 'N')
	{
		plr->x.dir = 0;
		plr->y.dir = -1;
		plr->x.plane = 0.66;
		plr->y.plane = 0;
		plr->y.cord += 0.03;
	}
	else
	{
		plr->x.dir = 0;
		plr->y.dir = 1;
		plr->x.plane = -0.66;
		plr->y.plane = 0;
	}
}

void	ft_plr_EW(char idn, t_plr *plr)
{
	if (idn == 'E')
	{
		plr->x.dir = 1;
		plr->y.dir = 0;
		plr->x.plane = 0;
		plr->y.plane = 0.66;
	}
	else
	{
		plr->x.dir = -1;
		plr->y.dir = 0;
		plr->x.plane = 0;
		plr->y.plane = -0.66;
		plr->x.cord += 0.03;
	}
}

void	ft_init_player(char **map, t_plr *plr, t_list **free_lst)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NEWS", map[y][x]))
			{
				count += 1;
				plr->x.cord = x + 0.5;
				plr->y.cord = y + 0.5;
				if (map[y][x] == 'N' || map[y][x] == 'S')
					ft_plr_NS(map[y][x], plr);
				else
					ft_plr_EW(map[y][x], plr);
			}
		}
	}
	if (count != 1)
		ft_error(-21, free_lst);
}
