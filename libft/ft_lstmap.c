#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	elem = ft_lstnew(f(lst->content));
	if (!elem)
	{
		ft_lstclear(&elem, del);
		return (NULL);
	}
	list = elem;
	lst = lst->next;
	while (lst)
	{
		list->next = ft_lstnew(f(lst->content));
		if (!list->next)
			ft_lstclear(&elem, del);
		else
		{
			lst = lst->next;
			list = list->next;
		}
	}
	return (elem);
}
