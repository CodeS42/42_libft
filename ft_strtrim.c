#include "libft.h"

static char	*copy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static int	is_set(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	start(char const *s1, char const *set, size_t fin)
{
	size_t	i;
	size_t	debut;

	i = 0;
	debut = 0;
	while (i <= fin)
	{
		if (is_set(s1[debut], set))
			i++;
		else
			return (debut);
		debut++;
	}
	return (0);
}

static size_t	end(char const *s1, char const *set)
{
	size_t	fin;

	fin = ft_strlen(s1) - 1;
	while (fin != 0)
	{
		if (is_set(s1[fin], set))
			fin--;
		else
			return (fin);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	debut;
	size_t	fin;
	char	*new;

	if (s1 == NULL || set == NULL)
		return (NULL);
	fin = end(s1, set);
	debut = start(s1, set, fin);
	if (debut == ft_strlen(s1))
		debut = 0;
	new = malloc((fin - debut + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);
	copy(new, &s1[debut], (fin - debut + 1) * sizeof(char));
	return (new);
}
