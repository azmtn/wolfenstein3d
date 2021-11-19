#include "cub.h"

void	ft_d_pl_init_new(t_all *all, t_plr *pl, t_pillar *ray, int i)
{
	ray->ind = i;
	ray->i_start = i;
	ray->cameraX = 2 * ray->ind / (double)pl->width - 1;
	ft_d_pl_init_new_1(&ray->x, &pl->x, ray->cameraX);
	ft_d_pl_init_new_1(&ray->y, &pl->y, ray->cameraX);
	while (all->map[ray->y.map][ray->x.map] != '1')
	{
		if (ray->x.sideDist < ray->y.sideDist)
		{
			ray->a = &ray->x;
			ray->b = &ray->y;
		}
		else
		{
			ray->a = &ray->y;
			ray->b = &ray->x;
		}
		ray->a->sideDist += ray->a->deltaDist;
		ray->a->map += ray->a->step;
	}
	pl->ray_dir[ray->ind] = ray->b->ray_dir;
	ray->a->pix = ray->a->map + (ray->a->ray_dir < 0);
	ft_d_pl_perp_new(ray, pl);
	ft_d_pl_perp_new1(all, ray, pl);
	pl->count++;
}

void	ft_draw_player_check(t_all *all, t_pillar *ray, \
											t_pillar *ray_n, t_pillar *tmp)
{
	t_plr	*pl;

	pl = all->plr;
	if (pl->perpWD[ray->i_start] - pl->perpWD[tmp->ind] > 0.5 && \
		pow(ray->x.map - tmp->x.map, 2) + pow(ray->y.map - tmp->y.map, 2) > 1)
	{
		ray_n->ind--;
		while (ray_n->x.map != ray->x.map || ray_n->y.map != ray->y.map)
		{
			while (ft_k_check(ray_n, pl) && ray_n->ind > ray->i_start)
			{
				ft_d_pl_perp_new1(all, ray_n, pl);
				ray_n->ind--;
			}
			if (ray_n->x.map != ray->x.map || ray_n->y.map != ray->y.map)
				ft_d_pl_init_new(all, pl, ray_n, ray_n->ind);
		}
	}
}

void	ft_draw_player_test(t_all *all, t_plr *pl)
{
	t_pillar	ray;
	t_pillar	ray_n;
	t_pillar	tmp;

	pl->count = 0;
	ft_d_pl_init_new(all, pl, &ray, 0);
	while (++ray.ind < pl->width)
	{
		while (ft_k_check(&ray, pl) && ray.ind < pl->width - 1)
			ray.ind++;
		ft_d_pl_init_new(all, pl, &tmp, ray.ind);
		ft_pillar_copy(&ray_n, &tmp);
		ft_draw_player_check(all, &ray, &ray_n, &tmp);
		ray.ind = ray.i_start;
		while (++ray.ind < ray_n.ind)
			ft_d_pl_perp_new1(all, &ray, pl);
		ft_pillar_copy(&ray, &tmp);
	}
}
