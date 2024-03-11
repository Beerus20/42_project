#include <stdio.h>
#include "./printf/includes/ft_printf.h"

int	main(void)
{
	int	nb;
	int	test;

	test = -1;
	nb = 0;
	nb = ft_printf("[%d]", test);
	printf("\n\tNB	: [%d]\n", nb);
	nb = printf("[%010d]", test);
	printf("\n\tNB	: [%d]\n", nb);
	return (0);
}
