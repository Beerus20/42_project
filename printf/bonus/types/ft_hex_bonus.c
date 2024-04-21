#include "../../includes/ft_hex_bonus.h"

int	ft_get_len_hex(int flags[7], unsigned long nb)
{
	int	len;

	len = ft_unblen(nb, 16);
	if (nb == 0 && flags[6] == 0)
		len = 0;
	if (flags[6] >= len)
		len = flags[6];
	if (flags[4] && flags[6] != 0 && nb != 0)
		len += 2;
	if (flags[5] > len)
		len = flags[5];
	return (len);
}

int	ft_manage_hexlen(unsigned long nb, int flags[7])
{
	int	len;

	len = ft_unblen(nb, 16);
	if (nb == 0 && flags[6] == 0)
		len = 0;
	if (flags[5] > (flags[6] + flags[4]))
	{
		if (flags[6] > len)
			flags[5] = flags[5] - flags[4] - flags[6];
		else
			flags[5] = flags[5] - flags[4] - len;
	}
	else
		flags[5] = 0;
	return (len);
}

char	*ft_apply_hash_flag(char *text, int flags[7], unsigned long nb, int type)
{
	if (flags[4] && flags[6] != 0 && nb != 0)
	{
		*(text++) = '0';
		if (type == 0)
			*(text++) = 'x';
		else
			*(text++) = 'X';
	}
	return (text);
}

// char	*ft_apply_flags_hex(char *text, int flags[7], long nb , int len)
// {
// 	if (flags[4] && flags[6] != 0 && nb != 0)
// 	{
// 		*(text++) = '0';
// 		if (type == 0)
// 			*(text++) = 'x';
// 		else
// 			*(text++) = 'X';
// 	}
// 	text += ft_add_blank(text, '0', flags[6] - len);
// 	return (text);
// }


int	ft_add_hex_value(char *text, int flags[7], unsigned long nb, int type)
{
	int		len;
	int		r_len;
	char	*base[2];

	base[0] = "0123456789abcdef";
	base[1] = "0123456789ABCDEF";
	r_len = ft_get_len_hex(flags, nb);
	len = ft_manage_hexlen(nb, flags);
	if (flags[0])
	{
		text = ft_apply_hash_flag(text, flags, nb, type);
		text += ft_add_blank(text, '0', flags[6] - len);
		text += ft_put_nb(text, nb, flags[6], base[type]);
		ft_add_blank(text, ' ', flags[5]);
	}
	else
	{
		if (flags[2] && flags[6] == -1)
			text += ft_add_blank(text, '0', flags[5]);
		else
			text += ft_add_blank(text, ' ', flags[5]);
		text = ft_apply_hash_flag(text, flags, nb, type);
		text += ft_add_blank(text, '0', flags[6] - len);
		ft_put_nb(text, nb, flags[6], base[type]);
	}
	return (r_len);
}

