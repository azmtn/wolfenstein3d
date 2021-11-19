#include "cub.h"

void 	ft_error(int key, t_list **free_list)
{
	if (key < 0)
		ft_putendl_fd("Error", 2);
	if (!free_list)
		ft_lstclear(free_list, free);
	exit(0);
}
