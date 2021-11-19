#include "cub.h"

void	ft_d_pl_init_new_1(t_axis *a, t_plq *pl, double cX)
{
	a->plr = pl;
	a->ray_dir = pl->dir + pl->plane * cX;
	a->map = (int)pl->cord;
	a->deltaDist = fabs(1 / a->ray_dir);
	if (a->ray_dir >= 0)
	{
		a->step = 1;
		a->sideDist = (a->map + 1.0 - pl->cord) * a->deltaDist;
	}
	else
	{
		a->step = -1;
		a->sideDist = (pl->cord - a->map) * a->deltaDist;
	}
}

void	ft_d_pl_perp_new(t_pillar *ray, t_plr *pl)
{
	pl->perpWD[ray->ind] = (ray->a->map - ray->a->plr->cord + \
			(1 - ray->a->step) / 2) / ray->a->ray_dir;
	ray->b->pix = ray->b->plr->cord + pl->perpWD[ray->ind] * \
			pl->ray_dir[ray->ind];
}

void	ft_d_pl_perp_new1(t_all *all, t_pillar *ray, t_plr *pl)
{
	ray->lineHeight = (int)(pl->width / pl->perpWD[ray->ind] * 0.75);
	if (ray->a == &ray->x)
	{
		if (ray->a->ray_dir < 0)
			return (texdrow(all, ray, &all->win->tex_WE));
		return (texdrow(all, ray, &all->win->tex_EA));
	}
	else
	{
		if (ray->a->ray_dir < 0)
			return (texdrow(all, ray, &all->win->tex_NO));
		return (texdrow(all, ray, &all->win->tex_SO));
	}
}

void	ft_pillar_copy(t_pillar *a, t_pillar *b)
{
	*a = *b;
	if (b->a == &b->x)
	{
		a->a = &a->x;
		a->b = &a->y;
	}
	else
	{
		a->a = &a->y;
		a->b = &a->x;
	}
}

int	ft_k_check(t_pillar *ray, t_plr *pl)
{
	int	k;

	k = ray->b->map + 1;
	ray->cameraX = 2 * ray->ind / (double)pl->width - 1;
	ray->a->ray_dir = ray->a->plr->dir + ray->a->plr->plane * ray->cameraX;
	pl->ray_dir[ray->ind] = ray->b->plr->dir + \
										ray->b->plr->plane * ray->cameraX;
	ft_d_pl_perp_new(ray, pl);
	return (!(ray->b->pix >= k || ray->b->pix + 1 < k));
}
