#ifndef CUB_H
# define CUB_H

# ifdef __linux__
#  include "libmlx-linux/mlx.h"
# else
#  include "libmlx/mlx.h"
# endif

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "keycodes.h"
# include <fcntl.h>
# include <math.h>

# define MAX_SIZE 16383

# define M_SPEED 0.1
# define R_SPEED 0.1

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct s_plq
{
	double		cord;
	double		dir;
	double		plane;
}				t_plq;

typedef struct s_axis
{
	int			step;
	double		sideDist;
	double		deltaDist;
	double		ray_dir;
	int			map;
	int			pix;
	t_plq		*plr;
}				t_axis;

typedef struct s_pillar
{
	t_axis		x;
	t_axis		y;
	t_axis		*a;
	t_axis		*b;
	double		cameraX;
	int			ind;
	int			i_start;
	int			lineHeight;

}				t_pillar;

typedef struct s_pair
{
	double	first;
	int		second;
}					t_pair;

typedef struct s_sprite
{
	double		x;
	double		y;

}				t_sprite;

typedef struct s_tex
{
	int			drawStart;
	int			drawEnd;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	int			color;
}				t_tex;

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_spr
{
	t_img		*tex;
	int			numSprites;
	t_sprite	*sprite;
	int			*sprOrder;
	double		*sprDistance;
	t_pair		*sprites;
	double		sprX;
	double		sprY;
	double		invDet;
	double		tX;
	double		tY;
	int			sprScreenX;
	int			vMoveScreen;
	int			sprHeight;
	int			drawStartY;
	int			drawEndY;
	int			sprWidth;
	int			drawStartX;
	int			drawEndX;
	int			texX;
	int			d;
	int			texY;
	int			color;
}				t_spr;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	t_img		tex_NO;
	t_img		tex_SO;
	t_img		tex_WE;
	t_img		tex_EA;
	t_img		tex_S;
}				t_win;

typedef struct s_pars
{
	char		*R;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	char		*F;
	char		*C;
}				t_pars;

typedef struct s_plr
{
	t_pars		ids;
	int			width;
	int			height;
	int			floor_color;
	int			ceiling_color;
	t_plq		x;
	t_plq		y;
	double		*perpWD;
	double		*ray_dir;
	int			count;
}				t_plr;

typedef struct s_key
{
	int			W;
	int			S;
	int			A;
	int			D;
	int			LEFT;
	int			RIGHT;
}				t_key;

typedef struct s_all
{
	t_win		*win;
	t_plr		*plr;
	t_key		key;
	t_spr		spr;
	char		**map;
	t_list		*free_lst;
}				t_all;

char	**ft_read_map(char *file, t_plr *plr, t_list **free_lst);
int		key_up(t_all *all);
int		key_cross(t_all *all);
int		key_press(int key, t_all *all);
int		key_release(int key, t_all *all);
void	pixel_put(t_win *win, int x, int y, int color);
int		ft_is_space(int c);
void	ft_draw_player_test(t_all *all, t_plr *pl);
void	ft_d_pl_init_new_1(t_axis *a, t_plq *pl, double cX);
void	ft_d_pl_perp_new(t_pillar *ray, t_plr *pl);
void	ft_d_pl_perp_new1(t_all *all, t_pillar *ray, t_plr *pl);
void	ft_d_pl_init_new(t_all *all, t_plr *pl, t_pillar *ray, int i);
void	ft_pillar_copy(t_pillar *a, t_pillar *b);
int		ft_k_check(t_pillar *ray, t_plr *pl);
void	load_texture(t_win *win, t_pars *ids, t_list **free_lst);
void	texdrow(t_all *all, t_pillar *ray, t_img *texture);
char	*ft_skip_space(char *str);
int		sort_sprite(char **map);
void	calc_sprite(char **map, t_sprite *sprite);
void	sort_order(t_pair *orders, int amount);
void	sortSprites(int *order, double *dist, int amount, t_pair *spr);
void	ft_draw_sprite(t_all *all, t_plr *pl);
void	sprite_malloc(t_all *all);
void	ft_screen(t_all *all);
void	ft_init_player(char **map, t_plr *plr, t_list **free_lst);
int		main_loop(t_all *all);
void	ft_error(int key, t_list **free_list);
void	ft_parst_clear(t_pars *pars);
int		ft_atoi_ud(const char *str);
int		ft_empty_field(t_pars *pars);
int		ft_pars_r(char *str, int *w, int *h);
int		ft_pars_let(t_pars *pars, char *str);
void	keyWS(t_all *all, t_plq *x, t_plq *y);
void	keyAD(t_all *all, t_plq *x, t_plq *y);
void	keyLR(t_all *all, t_plq *x, t_plq *y);
char	ft_after_whitespace(char *str);
int		ft_map_valid_check(char **map);
void	ft_start_game(t_all *all);

#endif