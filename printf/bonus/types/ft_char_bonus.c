#include "../../includes/ft_char_bonus.h"

int	ft_get_len_char(int flags[7], int c)
{
	(void)c;
	if (flags[5])
		return (flags[5]);
	return (1);
}

int	ft_add_char_value(char *text, int flags[7], int c)
{
	if (flags[5] >= 1)
		flags[5] = flags[5] - 1;
	if (flags[0])
	{
		*(text++) = c;
		ft_add_blank(text, ' ', flags[5]);
	}
	else
	{
		text += ft_add_blank(text, ' ', flags[5]);
		*text = c;
	}
	return (flags[5] + 1);
}