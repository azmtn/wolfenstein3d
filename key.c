#include "cub.h"

int 	key_up(t_all *all)
{
	t_plq	*x;
	t_plq	*y;

	x = &all->plr->x;
	y = &all->plr->y;
	if (all->key.W || all->key.S)
		keyWS(all, x, y);
	if (all->key.A || all->key.D)
		keyAD(all, x, y);
	if (all->key.LEFT || all->key.RIGHT)
		keyLR(all, x, y);
	return (0);
}

int	key_cross(t_all *all)
{
	ft_error(1, &all->free_lst);
	return (0);
}

int 	key_press(int key, t_all *all)
{
	if (key == K_ESC)
		ft_error(1, &all->free_lst);
	if (key == K_W || key == K_UP)
		all->key.W = 1;
	else if (key == K_S || key == K_DOWN)
		all->key.S = 1;
	else if (key == K_A)
		all->key.A = 1;
	else if (key == K_D)
		all->key.D = 1;
	else if (key == K_LEFT)
		all->key.LEFT = 1;
	else if (key == K_RIGHT)
		all->key.RIGHT = 1;
	return (0);
}

int 	key_release(int key, t_all *all)
{
	if (key == K_ESC)
		ft_error(1, &all->free_lst);
	if (key == K_W || key == K_UP)
		all->key.W = 0;
	else if (key == K_S || key == K_DOWN)
		all->key.S = 0;
	else if (key == K_A)
		all->key.A = 0;
	else if (key == K_D)
		all->key.D = 0;
	else if (key == K_LEFT)
		all->key.LEFT = 0;
	else if (key == K_RIGHT)
		all->key.RIGHT = 0;
	return (0);
}
