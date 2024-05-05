#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*actuel;
	int		nbelement;

	actuel = lst;
	nbelement = 0;
	while (actuel != NULL)
	{
		actuel = actuel->next;
		nbelement++;
	}
	return (nbelement);
}
