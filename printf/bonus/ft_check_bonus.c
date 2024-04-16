#include "../includes/ft_check_bonus.h"

int	ft_check_desc(char c)
{
	int		i;
	char	*desc;

	i = 0;
	desc = "cspduixX%";
	while (desc[i])
	{
		if (desc[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_value(char *str, char c)
{
	while (!ft_check_desc(*str) && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_check_extra_len(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (!ft_check_desc(str[i]))
		i++;
	if (str[i] == 'i' || str[i] == 'd')
	{
		len += ft_check_value(str, ' ');
		len += ft_check_value(str, '+');
	}
	if ((str[i] == 'x' || str[i] == 'X') && ft_check_value(str, '#'))
		len += 2;
	return (len);
}
