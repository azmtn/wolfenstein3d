#include "cub.h"
void	ft_start_part_1(t_all *all)
{
	int		max_w;
	int		max_h;
	t_win	*win;
	t_plr	*plr;

	win = all->win;
	plr = all->plr;
	ft_init_player(all->map, all->plr, &all->free_lst);
	sprite_malloc(all);
	mlx_get_screen_size(&max_w, &max_h);
	if (plr->width > max_w)
		plr->width = max_w;
	if (plr->height > max_h)
		plr->height = max_h;
	win->mlx = mlx_init();
	if (!win->mlx)
		ft_error(-3, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(win->mlx));
	win->win = mlx_new_window(win->mlx, plr->width, plr->height, "cub3D");
	if (!win->win)
		ft_error(-4, &all->free_lst);
}

void	ft_start_game(t_all *all)
{
	t_win	*win;
	t_plr	*plr;

	win = all->win;
	plr = all->plr;
	ft_start_part_1(all);
	load_texture(win, &plr->ids, &all->free_lst);
	win->img = mlx_new_image(win->mlx, plr->width, plr->height);
	if (!win->img)
		ft_error(-5, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(win->img));
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->en);
	if (!win->addr)
		ft_error(-6, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(win->addr));
	mlx_loop_hook(win->mlx, &main_loop, all);
	mlx_hook(win->win, 2, (1L << 0), &key_press, all);
	mlx_hook(win->win, 17, (1L << 0), &key_cross, all);
	mlx_hook(win->win, 3, (1L << 1), &key_release, all);
	mlx_loop(win->mlx);
}
