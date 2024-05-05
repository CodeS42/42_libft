#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	new = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = (f)(i, s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
