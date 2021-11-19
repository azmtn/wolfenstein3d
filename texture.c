#include "cub.h"

void	ft_init_texture(t_win *win, char *path, t_img *img, t_list **free_lst)
{
	img->img = mlx_xpm_file_to_image(win->mlx, path, \
								  &img->img_width, \
								  &img->img_height);
	if (!img->img)
		ft_error(-5, free_lst);
	ft_lstadd_back(free_lst, ft_lstnew(win->img));
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_l, &img->en);
	if (!img->addr)
		ft_error(-6, free_lst);
	ft_lstadd_back(free_lst, ft_lstnew(win->addr));
}

void	load_texture(t_win *win, t_pars *ids, t_list **free_lst)
{
	ft_init_texture(win, ft_skip_space(ids->NO + 3), &win->tex_NO, free_lst);
	ft_init_texture(win, ft_skip_space(ids->SO + 3), &win->tex_SO, free_lst);
	ft_init_texture(win, ft_skip_space(ids->WE + 3), &win->tex_WE, free_lst);
	ft_init_texture(win, ft_skip_space(ids->EA + 3), &win->tex_EA, free_lst);
	ft_init_texture(win, ft_skip_space(ids->S + 2), &win->tex_S, free_lst);
}

int	tex_init(t_all *all, t_pillar *ray, t_img *texture, t_tex *tex)
{
	tex->drawStart = -ray->lineHeight / 2 + all->plr->height / 2;
	if (tex->drawStart < 0)
		tex->drawStart = 0;
	tex->drawEnd = ray->lineHeight / 2 + all->plr->height / 2;
	if (tex->drawEnd >= all->plr->height || tex->drawEnd < 0)
		tex->drawEnd = all->plr->height - 1;
	if (tex->drawStart > tex->drawEnd)
		return (0);
	tex->wall_x = ray->b->plr->cord + all->plr->perpWD[ray->ind] * \
			all->plr->ray_dir[ray->ind];
	tex->wall_x -= floor(tex->wall_x);
	tex->tex_x = (int)(tex->wall_x * (double)texture->img_width);
	if (ray->a == &ray->x && ray->x.ray_dir > 0)
		tex->tex_x = texture->img_width - tex->tex_x - 1;
	if (ray->a == &ray->y && ray->y.ray_dir < 0)
		tex->tex_x = texture->img_width - tex->tex_x - 1;
	tex->step = texture->img_height / (double)ray->lineHeight;
	tex->tex_pos = (tex->drawStart - all->plr->height / 2 + \
			(ray->lineHeight / 2)) * tex->step;
	return (1);
}

void	texdrow(t_all *all, t_pillar *ray, t_img *texture)
{
	t_tex	tex;
	int		y;

	if (!tex_init(all, ray, texture, &tex))
		return ;
	y = 0;
	while (y < tex.drawStart)
		pixel_put(all->win, ray->ind, y++, all->plr->ceiling_color);
	while (y < tex.drawEnd)
	{
		tex.tex_y = (int)tex.tex_pos;
		tex.tex_pos += tex.step;
		tex.color = *(unsigned int *)(texture->addr + \
		(tex.tex_y * texture->line_l + tex.tex_x * (texture->bpp / 8)));
		pixel_put(all->win, ray->ind, y++, tex.color);
	}
	while (y < all->plr->height)
		pixel_put(all->win, ray->ind, y++, all->plr->floor_color);
}
