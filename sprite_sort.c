#include "cub.h"

int	sort_sprite(char **map)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x++] == '2')
				i++;
		}
		y++;
	}
	return (i);
}

void	calc_sprite(char **map, t_sprite *sprite)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
			{
				sprite[i].x = x + 0.5;
				sprite[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sortSprites(int *order, double *dist, int amount, t_pair *spr)
{
	int	i;

	i = 0;
	while (i < amount)
	{
		spr[i].first = dist[i];
		spr[i].second = order[i];
		i++;
	}
	sort_order(spr, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = spr[amount - i - 1].first;
		order[i] = spr[amount - i - 1].second;
		i++;
	}
}
