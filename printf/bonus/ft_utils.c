#include "../includes/ft_utils_bonus.h"

int	ft_add_blank(char *text, char c, int e)
{
	int	i;

	i = 0;
	while (i < e)
	{
		*(text++) = c;
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	while (str[i++])
		len++;
	return (len);
}

int	ft_unblen(unsigned long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int	ft_put_nb(char *text, unsigned long nb, int prec, char *base)
{
	int	i;
	int	len;
	int	nb_base;

	i = 1;
	if (nb == 0)
	{
		if (prec == 0)
			return (0);
		*(text) = '0';
		return (1);
	}
	nb_base = ft_strlen(base);
	len = ft_unblen(nb, nb_base);
	while (nb)
	{
		text[len - (i++)] = base[nb % nb_base];
		nb /= nb_base;
	}
	return (len);
}
