#include "cub.h"

char	**ft_make_map(t_list **head, int size, t_list **free_lst)
{
	char	**map;
	int		i;
	t_list	*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		ft_error(-20, free_lst);
	ft_lstadd_back(free_lst, ft_lstnew(map));
	i = -1;
	tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	ft_lstadd_back(free_lst, *head);
	if (!ft_map_valid_check(map))
		ft_error(-12, free_lst);
	return (map);
}

int	ft_pars_color1(char **str, t_list **free_lst)
{
	int	tmp;

	while (**str && **str == ' ')
		(*str)++;
	tmp = ft_atoi_ud(*str);
	if (tmp < 0 || tmp > 255)
		ft_error(-11, free_lst);
	while (**str && **str != ' ' && **str != ',')
		(*str)++;
	return (tmp);
}

void	ft_pars_color(char *str, int *color, t_list **free_lst)
{
	*color = 0;
	*color = (*color | ft_pars_color1(&str, free_lst)) << 8;
	while (*str == ',' || *str == ' ')
		str++;
	*color = (*color | ft_pars_color1(&str, free_lst)) << 8;
	while (*str == ',' || *str == ' ')
		str++;
	*color = *color | ft_pars_color1(&str, free_lst);
	while (ft_is_space(*str))
		str++;
	if (*str != '\0')
		ft_error(-21, free_lst);
}

void	ft_wid_made(char **str, t_plr *plr, int fd, t_list **free_lst)
{
	int	ids_count;

	ids_count = 0;
	ft_parst_clear(&plr->ids);
	while (get_next_line(fd, str) > 0 && ft_strchr("RNSWESFC\0", \
												ft_after_whitespace(*str)))
	{
		if (ft_after_whitespace(*str) != '\0')
		{
			if (!ft_pars_let(&plr->ids, *str))
				ft_error(-8, free_lst);
			ft_lstadd_back(free_lst, ft_lstnew(*str));
			ids_count++;
		}
		else
			free(*str);
	}
	if (ids_count != 8 || ft_empty_field(&plr->ids))
		ft_error(-9, free_lst);
	if (!ft_pars_r(plr->ids.R + 2, &plr->width, &plr->height))
		ft_error(-10, free_lst);
	ft_pars_color(plr->ids.F + 2, &plr->floor_color, free_lst);
	ft_pars_color(plr->ids.C + 2, &plr->ceiling_color, free_lst);
}

char	**ft_read_map(char *file, t_plr *plr, t_list **free_lst)
{
	char	*str;
	t_list	*head;
	int		fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error(-7, free_lst);
	str = 0;
	head = 0;
	ft_wid_made(&str, plr, fd, free_lst);
	ft_lstadd_back(&head, ft_lstnew(str));
	while (get_next_line(fd, &str) > 0)
		ft_lstadd_back(&head, ft_lstnew(str));
	ft_lstadd_back(&head, ft_lstnew(str));
	close(fd);
	return (ft_make_map(&head, ft_lstsize(head), free_lst));
}
