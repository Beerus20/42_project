#include <stdio.h>
#include "./printf/includes/ft_printf.h"

int	main(void)
{
	int	nb;
	int	test;

	test = -100;
	nb = 0;
	nb = ft_printf(" [%x]", test);
	printf("\nNB	: [%d]\n", nb);
	nb = printf(" [%x]", test);
	printf("\nNB	: [%d]\n", nb);
	return (0);
}
