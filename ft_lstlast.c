#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actuel;

	if (lst == NULL)
		return (NULL);
	actuel = lst;
	while (actuel->next != NULL)
		actuel = actuel->next;
	return (actuel);
}
