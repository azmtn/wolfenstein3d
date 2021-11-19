#include "cub.h"

int	main_loop(t_all *all)
{
	t_win	*win;

	win = all->win;
	ft_draw_player_test(all, all->plr);
	ft_draw_sprite(all, all->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	key_up(all);
	return (0);
}

void	ft_argc_check(t_all *all, int argc, char **argv)
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (len < 4)
			ft_error(-23, &all->free_lst);
		if (ft_strncmp(".cub", argv[1] + len - 4, 5) != 0)
			ft_error(-24, &all->free_lst);
		all->map = ft_read_map(argv[1], all->plr, &all->free_lst);
		ft_start_game(all);
	}
	else if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 7) == 0)
		{
			all->map = ft_read_map(argv[1], all->plr, &all->free_lst);
			ft_screen(all);
		}
		else
			ft_error(-2, &all->free_lst);
	}
	else
		ft_error(-25, &all->free_lst);
}

int	main(int argc, char **argv)
{
	t_win	win;
	t_plr	plr;
	t_all	all;

	all.plr = &plr;
	all.win = &win;
	all.free_lst = NULL;
	if (ft_strncmp("./cub3D", argv[0], 8) != 0)
		ft_error(-1, &all.free_lst);
	ft_argc_check(&all, argc, argv);
	ft_error(1, &all.free_lst);
	return (0);
}
