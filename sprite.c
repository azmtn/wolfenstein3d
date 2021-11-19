#include "cub.h"

void	spr_draw_iter(t_all *all, t_plr *pl, t_spr *spr)
{
	int	stripe;
	int	y;

	stripe = spr->drawStartX - 1;
	while (++stripe < spr->drawEndX)
	{
		spr->texX = (int)((256 * (stripe - (-spr->sprWidth / 2 + \
			spr->sprScreenX)) * spr->tex->img_width / spr->sprWidth) / 256);
		if (spr->tY > 0 && stripe > 0 && \
				stripe < pl->width && spr->tY < pl->perpWD[stripe])
		{
			y = spr->drawStartY - 1;
			while (++y < spr->drawEndY)
			{
				spr->d = (y - spr->vMoveScreen) * 256 - pl->height * 128 + \
													spr->sprHeight * 128;
				spr->texY = ((spr->d * spr->tex->img_height) / \
								spr->sprHeight) / 256;
				spr->color = *(unsigned int *)(spr->tex->addr + (spr->texY * \
						spr->tex->line_l + spr->texX * (spr->tex->bpp / 8)));
				if ((spr->color & 0x00FFFFFF) != 0)
					pixel_put(all->win, stripe, y, spr->color);
			}
		}
	}
}

void	spr_init(t_plr *pl, t_spr *spr, int i)
{
	spr->sprX = spr->sprite[spr->sprOrder[i]].x - pl->x.cord;
	spr->sprY = spr->sprite[spr->sprOrder[i]].y - pl->y.cord;
	spr->invDet = 1.0 / (pl->x.plane * pl->y.dir - pl->x.dir * pl->y.plane);
	spr->tX = spr->invDet * (pl->y.dir * spr->sprX - pl->x.dir * spr->sprY);
	spr->tY = spr->invDet * (-pl->y.plane * spr->sprX + \
			pl->x.plane * spr->sprY);
	spr->sprScreenX = (int)((pl->width / 2) * (1 + spr->tX / spr->tY));
	spr->vMoveScreen = (int)(VMOVE / spr->tY);
	spr->sprHeight = (int)fabs((pl->height / spr->tY) / VDIV);
	spr->drawStartY = -spr->sprHeight / 2 + pl->height / 2 + spr->vMoveScreen;
	if (spr->drawStartY < 0)
		spr->drawStartY = 0;
	spr->drawEndY = spr->sprHeight / 2 + pl->height / 2 + spr->vMoveScreen;
	if (spr->drawEndY >= pl->height)
		spr->drawEndY = pl->height - 1;
	spr->sprWidth = (int)fabs((pl->height / spr->tY) / UDIV);
	spr->drawStartX = -spr->sprWidth / 2 + spr->sprScreenX;
	if (spr->drawStartX < 0)
		spr->drawStartX = 0;
	spr->drawEndX = spr->sprWidth / 2 + spr->sprScreenX;
	if (spr->drawEndX >= pl->width)
		spr->drawEndX = pl->width - 1;
}

void	ft_draw_sprite(t_all *all, t_plr *pl)
{
	int		i;
	t_spr	spr;

	spr = all->spr;
	i = -1;
	while (++i < spr.numSprites)
	{
		spr.sprOrder[i] = i;
		spr.sprDistance[i] = ((pl->x.cord - spr.sprite[i].x) * \
		(pl->x.cord - spr.sprite[i].x) + (pl->y.cord - spr.sprite[i].y) * \
		(pl->y.cord - spr.sprite[i].y));
	}
	sortSprites(spr.sprOrder, spr.sprDistance, spr.numSprites, spr.sprites);
	i = -1;
	while (++i < spr.numSprites)
	{
		if (spr.sprDistance[i] < 0.2)
			continue ;
		spr_init(pl, &spr, i);
		spr_draw_iter(all, pl, &spr);
	}
}
