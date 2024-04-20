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