#include <stdio.h>
#include "./printf/includes/ft_printf.h"

int	main(void)
{
	int	nb;
	int	test;

	test = -1;
	nb = 0;
	nb = ft_printf(" [%p]", &test);
	printf("\nNB	: [%d]\n", nb);
	nb = printf(" [%p]", &test);
	printf("\nNB	: [%d]\n", nb);
	return (0);
}