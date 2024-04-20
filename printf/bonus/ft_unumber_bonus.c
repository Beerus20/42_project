#include "../includes/ft_unumber_bonus.h"

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

int	ft_manage_unblen(unsigned long nb, int prec)
{
	int	len;

	len = ft_unblen(nb, 10);
	if (nb == 0 && prec == 0)
		len = 0;
	if (prec >= len)
		len = prec;
	return (len);
}

int	ft_get_len_unb(int flags[7], unsigned long nb)
{
	int	len;

	len = ft_unblen(nb, 10);
	if (nb == 0 && flags[6] == 0)
		len = 0;
	if (flags[6] >= len)
		len = flags[6];
	if (flags[5] > len)
		len = flags[5];
	return (len);
}

int	ft_add_nb(char *text, unsigned long nb, char *base)
{
	int	i;
	int	len;
	int	nb_base;

	i = 1;
	if (nb == 0)
		return (ft_add_str(text, "0"));
	nb_base = ft_strlen(base);
	len = ft_u_nblen(nb, nb_base);
	while (nb)
	{
		text[len - (i++)] = base[nb % nb_base];
		nb /= nb_base;
	}
	return (len);
}

int	ft_add_unb_value(char *text, int flags[7], unsigned long nb)
{
	int	len;
	int	r_len;

	r_len = ft_get_len_unb(flags, nb);
	len = ft_unblen(str, flags[6]);
	if (flags[0])
	{
		text += ft_put_str(text, str, len);
		ft_add_blank(text, ' ', flags[5] - len);
	}
	else
	{
		text += ft_add_blank(text, ' ', flags[5] - len);
		ft_put_str(text, str, len);
	}
	return (0);
}

