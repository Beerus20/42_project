#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

int	main(void)
{
	char	*text;
	int	nb;

	nb = 0;
	text = "result	: [%.u]\n";
	printf("NB : %d\n", ft_printf(text, nb));
	printf("NB : %d\n", printf(text, nb));
	return (0);
}
