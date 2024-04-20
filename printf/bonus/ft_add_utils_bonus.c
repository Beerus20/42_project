#include "../includes/ft_add_bonus.h"

int	ft_add_blanc(char *text, char blanc, int s, int e)
{
	while (s < e)
	{
		if (text[s] == 0)
			text[s] = blanc;
		s++;
	}
	return (s);
}

int	ft_add_char_b(char *text, int flags[7], char c)
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

void	ft_manage_unblen(int len, int flags[7])
{
	if (flags[6] > len)
		flags[6] = flags[6] - len;
	else
		flags[6] = 0;
	if (flags[5] > flags[6] && flags[5] > len)
		flags[5] = flags[5] - flags[6] - len;
	else
		flags[5] = 0;
}

int	ft_add_unb_b(char *text, int flags[7], unsigned long nb, char *base)
{
	int	len;

	len = ft_u_nblen(nb, ft_strlen(base));
	ft_manage_unblen(len, flags);
	if (flags[0])
	{
		if (flags[6])
			text += ft_add_blanc(text, '0', 0, flags[6]);
		text += ft_add_unb(text, nb, base);
		if (flags[5])
			ft_add_blanc(text, ' ', 0, flags[5]);
	}
	else
	{
		if (flags[5])
			text += ft_add_blanc(text, ' ', 0, flags[5]);
		if (flags[6])
			text += ft_add_blanc(text, '0', 0, flags[6]);
		ft_add_unb(text, nb, base);
	}
	printf("r_len	: %d %d %d\n", flags[5], flags[6], len);
	return (flags[5] + flags[6] + len);
}
