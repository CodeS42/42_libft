#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new;
	t_list	*tmp;

	new_lst = NULL;
	if (lst == NULL)
		return (NULL);
	tmp = lst;
	while (tmp != NULL)
	{
		new = ft_lstnew((f)(tmp->content));
		if (new == NULL)
		{
			ft_lstclear(&new_lst, (del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new);
		tmp = tmp->next;
	}
	return (new_lst);
}
