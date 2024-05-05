#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tableau;

	tableau = NULL;
	if (size == 0)
		return (malloc(0));
	if (nmemb <= 0 && size <= 0)
		return (NULL);
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	tableau = malloc(nmemb * size);
	if (tableau == NULL)
		return (NULL);
	ft_memset(tableau, 0, nmemb * size);
	return (tableau);
}
