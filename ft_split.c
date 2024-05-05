#include "libft.h"

static int	is_sep_or_null(char c, char csep)
{
	if (c == csep || c == '\0')
		return (1);
	return (0);
}

static int	count_str(char const *s, char c)
{
	int	i;
	int	nbrstr;

	i = 0;
	nbrstr = 0;
	while (s[i])
	{
		if (is_sep_or_null(s[i + 1], c) && !is_sep_or_null(s[i], c))
			nbrstr++;
		i++;
	}
	return (nbrstr);
}

static void	print_word(char *dest, char const *s, char c)
{
	int	i;

	i = 0;
	while (!is_sep_or_null(s[i], c))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

static void	print_split(char **tabstr, char const *s, char c)
{
	int	i;
	int	j;
	int	mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		if (is_sep_or_null(s[i], c))
			i++;
		else
		{
			j = 0;
			while (!is_sep_or_null(s[i + j], c))
				j++;
			tabstr[mot] = malloc((j + 1) * sizeof(char));
			if (tabstr[mot] == NULL)
				return ;
			print_word(tabstr[mot], s + i, c);
			i += j;
			mot++;
		}
	}
	tabstr[mot] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tabstr;
	int		nbrstr;

	if (s == NULL)
		return (NULL);
	nbrstr = count_str(s, c);
	tabstr = malloc((nbrstr + 1) * sizeof(char *));
	if (tabstr == NULL)
		return (NULL);
	print_split(tabstr, s, c);
	return (tabstr);
}
