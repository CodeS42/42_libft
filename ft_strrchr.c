#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen(s);
	ch = (char)c;
	if (ch == 0)
		return ((char *)s + ft_strlen(s));
	while (i > 0)
	{
		if (s[i - 1] == ch)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}
