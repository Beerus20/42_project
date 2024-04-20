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
