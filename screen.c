#include "cub.h"

void	head_placeholder( t_all *all, unsigned char	**header, int size)
{
	(*header)[0] = (unsigned char)('B');
	(*header)[1] = (unsigned char)('M');
	(*header)[2] = (unsigned char)(size);
	(*header)[3] = (unsigned char)(size >> 8);
	(*header)[4] = (unsigned char)(size >> 16);
	(*header)[5] = (unsigned char)(size >> 24);
	(*header)[10] = (unsigned char)(14 + 40);
	(*header)[14 + 0] = (unsigned char)(40);
	(*header)[14 + 4] = (unsigned char)(all->plr->width);
	(*header)[14 + 5] = (unsigned char)(all->plr->width >> 8);
	(*header)[14 + 6] = (unsigned char)(all->plr->width >> 16);
	(*header)[14 + 7] = (unsigned char)(all->plr->width >> 24);
	(*header)[14 + 8] = (unsigned char)(all->plr->height);
	(*header)[14 + 9] = (unsigned char)(all->plr->height >> 8);
	(*header)[14 + 10] = (unsigned char)(all->plr->height >> 16);
	(*header)[14 + 11] = (unsigned char)(all->plr->height >> 24);
	(*header)[14 + 12] = (unsigned char)(1);
	(*header)[14 + 14] = (unsigned char)(all->win->bpp);
}

void	ft_img_hed(int fd, t_all *all)
{
	int				size;
	unsigned char	*header;

	size = 54 + (all->plr->width * all->plr->height) * \
				all->win->bpp / 8;
	header = ft_calloc(14 + 40, sizeof(unsigned char));
	if (!header)
		ft_error(-19, &all->free_lst);
	head_placeholder(all, &header, size);
	write(fd, header, 54);
	free(header);
}

void	screen_init(t_all *all, t_win *win, t_plr *plr)
{
	ft_init_player(all->map, all->plr, &all->free_lst);
	sprite_malloc(all);
	if (plr->width > MAX_SIZE)
		plr->width = MAX_SIZE;
	if (plr->height > MAX_SIZE)
		plr->height = MAX_SIZE;
	win->mlx = ft_calloc(8, 1);
	if (!win->mlx)
		ft_error(-3, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(win->mlx));
	load_texture(win, &plr->ids, &all->free_lst);
	win->img = mlx_new_image(win->mlx, all->plr->width, plr->height);
	if (!win->img)
		ft_error(-5, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(win->img));
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->en);
	if (!win->addr)
		ft_error(-6, &all->free_lst);
	ft_lstadd_back(&all->free_lst, ft_lstnew(win->addr));
	ft_draw_player_test(all, plr);
	ft_draw_sprite(all, plr);
}

void	ft_screen(t_all *all)
{
	int		fd;
	int		height;

	screen_init(all, all->win, all->plr);
	height = all->plr->height;
	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
	if (!fd)
		ft_error(-7, &all->free_lst);
	ft_img_hed(fd, all);
	while (--height)
		all->win->addr += all->win->line_l;
	while (height++ < all->plr->height)
	{
		write(fd, all->win->addr, all->plr->width * 4);
		all->win->addr -= all->win->line_l;
	}
	close(fd);
}
