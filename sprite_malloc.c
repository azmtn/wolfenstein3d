#include "cub.h"

void 	sprite_malloc_part_1(t_all *all, t_spr	*spr)
{
	spr->tex = &all->win->tex_S;
	spr->numSprites = sort_sprite(all->map);
	spr->sprite = malloc(sizeof(t_sprite) * spr->numSprites);
	if (!spr->sprite)
		ft_error(-13, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(spr->sprite));
	spr->sprOrder = malloc(sizeof(int) * spr->numSprites);
	if (!spr->sprOrder)
		ft_error(-14, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(spr->sprOrder));
	spr->sprDistance = malloc(sizeof(double) * spr->numSprites);
	if (!spr->sprDistance)
		ft_error(-15, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(spr->sprDistance));
}

void 	sprite_malloc_part_2(t_all *all, t_spr	*spr)
{
	spr->sprites = (t_pair *)malloc(sizeof(t_pair) * spr->numSprites);
	if (!spr->sprites)
		ft_error(-16, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(spr->sprites));
	calc_sprite(all->map, spr->sprite);
	all->plr->perpWD = malloc(sizeof(double) * all->plr->width);
	if (!all->plr->perpWD)
		ft_error(-17, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(all->plr->perpWD));
	all->plr->ray_dir = malloc(sizeof(double) * all->plr->width);
	if (!all->plr->ray_dir)
		ft_error(-18, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(all->plr->ray_dir));
}

void 	sprite_malloc(t_all *all)
{
	t_spr	*spr;

	spr = &all->spr;
	sprite_malloc_part_1(all, spr);
	sprite_malloc_part_2(all, spr);
}
