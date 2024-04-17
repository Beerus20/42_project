#include "../includes/ft_add_bonus.h"

int	ft_add_blanc(char *text, char blanc, int s, int e)
{
	while (s < e)
		text[s++] = blanc;
	return (s);
}

int	ft_add_text(char *text, char *str, int s, int e)
{
	int	len;

	len = ft_strlen(str);
	if (e > len)
		e = len;
	while (s < e)
		text[s++] = *(str++);
	return (s);
}

int	ft_add_char(char *text, int	flags[7], char c)
{
	int	i;

	i = 0;
	if (flags[0])
	{
		text[i++] = c;
		ft_add_blanc(text, ' ', i, flags[5]);
	}
	else
	{
		i += ft_add_blanc(text, ' ', i, flags[5] - 1);
		text[i] = c;
	}
	if (flags[5])
		return (flags[5]);
	return (1);
}

char	*ft_add_null_str(int flags[7])
{
	char	*r_value;

	r_value = " ";
	if (flags[6] != -1 && flags[6] < 6)
		flags[6] = 1;
	else
		r_value = "(null)";
	return (r_value);
}

int	ft_add_str(char *text, int flags[7], char *str)
{
	int		i;
	int		len;
	int		width;

	i = 0;
	width = flags[5];
	if (!str)
		str = ft_add_null_str(flags);
	len = ft_strlen(str);
	if (flags[6] != -1 && flags[6] < len)
		len = flags[6];
	if (len > flags[5])
		width = len;
	if (flags[0])
	{
		i += ft_add_text(text, str, 0, len);
		ft_add_blanc(text, ' ', i, width);
	}
	else
	{
		i += ft_add_blanc(text, ' ', 0, width - len);
		ft_add_text(text + i, str, 0, len);
	}
	return (width);
}

int	ft_add_unb(char *text, int flags[6], unsigned long nb, char *base)
{
	int	i;
	int	len;
	int	width;
	int	nb_base;

	i = 1;
	// if (nb == 0)
	// 	return (ft_add_str(text, "0"));
	nb_base = ft_strlen(base);
	len = ft_u_nblen(nb, nb_base);
	width = len;
	if (width < flags[5] && !flags[0])
		width = flags[5];
	while (nb)
	{
		text[width - (i++)] = base[nb % nb_base];
		nb /= nb_base;
	}
	if (!flags[0])
		ft_add_blanc(text, ' ', 0, width - len);
	else
	{
		i--;
		if (flags[5] > width)
		{
			ft_add_blanc(text + i, ' ', 0, flags[5]);
			return (flags[5]);
		}
		else
			ft_add_blanc(text + i, ' ', i, width);
	}
	return (width);
}

// int	ft_add_nb(char *text, int flags[6], long nb)
// {
// 	int	len;

// 	len = 0;
// 	if (!nb)
// 		return (ft_add_str(text, "0"));
// 	if (nb < 0)
// 	{
// 		*(text++) = '-';
// 		len++;
// 		nb = -nb;
// 	}
// 	len += ft_add_unb(text, nb, "0123456789");
// 	return (len);
// }

// int	ft_add_pointer(char *text, int	flags[6], unsigned long nb)
// {
// 	int		len;

// 	len = 0;
// 	if (!nb)
// 		return (ft_add_str(text, "(nil)"));
// 	*(text++) = '0';
// 	*(text++) = 'x';
// 	len = ft_add_unb(text, nb, "0123456789abcdef");
// 	return (len + 2);
// }