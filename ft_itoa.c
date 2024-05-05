#include "libft.h"

static int	count_c(int n)
{
	int				nc;
	unsigned int	nbr;

	nc = 0;
	if (n < 0)
	{
		nc++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		nc++;
	}
	return (++nc);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				nc;
	int				i;
	unsigned int	nbr;

	nc = count_c(n);
	str = malloc((nc + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = nc - 1;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 9)
	{
		str[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	str[i] = nbr + '0';
	str[nc] = 0;
	return (str);
}
