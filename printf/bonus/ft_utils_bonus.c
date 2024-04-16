#include "../includes/ft_utils_bonus.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_get_width(char *str)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (!(str[i] >= '1' && str[i] <= '9') && !ft_check_desc(str[i]))
	{
		if (str[i] == '.')
			return (width);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && !ft_check_desc(str[i]))
	{
		width = (str[i] - 48) + (width * 10);
		i++;
	}
	return (width);
}
int	ft_get_precision(char *str)
{
	int	i;
	int	prec;

	i = 0;
	prec = 0;
	while (str[i++] != '.' && !ft_check_desc(str[i]))
		;
	while ((str[i] >= '0' && str[i] <= '9') && !ft_check_desc(str[i]))
	{
		prec = (str[i] - 48) + (prec * 10);
		i++;
	}
	return (prec);
}