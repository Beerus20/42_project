#include "../includes/ft_flags_bonus.h"

int	ft_isdesc(int c)
{
	char *desc;

	desc = "cspdiuxX%";
	while (*desc)
	{
		if (*desc == c)
			return (1);
		desc++;
	}
	return (0);
}