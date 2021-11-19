#include "cub.h"

void	keyWS(t_all *all, t_plq *x, t_plq *y)
{
	double	tmp;

	if (all->key.W)
	{
		tmp = y->cord + y->dir * M_SPEED;
		if (all->map[(int)tmp][(int)x->cord] != '1')
			y->cord = tmp;
		tmp = x->cord + x->dir * M_SPEED;
		if (all->map[(int)y->cord][(int)tmp] != '1')
			x->cord = tmp;
	}
	if (all->key.S)
	{
		tmp = y->cord - y->dir * M_SPEED;
		if (all->map[(int)tmp][(int)x->cord] != '1')
			y->cord = tmp;
		tmp = x->cord - x->dir * M_SPEED;
		if (all->map[(int)y->cord][(int)tmp] != '1')
			x->cord = tmp;
	}
}

void	keyAD(t_all *all, t_plq *x, t_plq *y)
{
	double	tmp;

	if (all->key.A)
	{
		tmp = y->cord - x->dir * M_SPEED;
		if (all->map[(int)tmp][(int)x->cord] != '1')
			y->cord = tmp;
		tmp = x->cord + y->dir * M_SPEED;
		if (all->map[(int)y->cord][(int)tmp] != '1')
			x->cord = tmp;
	}
	if (all->key.D)
	{
		tmp = y->cord + x->dir * M_SPEED;
		if (all->map[(int)tmp][(int)x->cord] != '1')
			y->cord = tmp;
		tmp = x->cord - y->dir * M_SPEED;
		if (all->map[(int)y->cord][(int)tmp] != '1')
			x->cord = tmp;
	}
}

void	keyLR(t_all *all, t_plq *x, t_plq *y)
{
	double	tmp;

	if (all->key.LEFT)
	{
		tmp = x->dir;
		x->dir = x->dir * cos(-R_SPEED) - y->dir * sin(-R_SPEED);
		y->dir = tmp * sin(-R_SPEED) + y->dir * cos(-R_SPEED);
		tmp = x->plane;
		x->plane = x->plane * cos(-R_SPEED) - y->plane * sin(-R_SPEED);
		y->plane = tmp * sin(-R_SPEED) + y->plane * cos(-R_SPEED);
	}
	if (all->key.RIGHT)
	{
		tmp = x->dir;
		x->dir = x->dir * cos(R_SPEED) - y->dir * sin(R_SPEED);
		y->dir = tmp * sin(R_SPEED) + y->dir * cos(R_SPEED);
		tmp = x->plane;
		x->plane = x->plane * cos(R_SPEED) - y->plane * sin(R_SPEED);
		y->plane = tmp * sin(R_SPEED) + y->plane * cos(R_SPEED);
	}
}
