#include <stdio.h>
#include "./printf/includes/ft_printf.h"

int	main(void)
{
	int	nb;

	nb = 0;
	nb = ft_printf("This %.p is even stranger", (void *)-1);
	printf("\n\tNB	: [%d]\n", nb);
	nb = printf("This %p is even stranger", (void *)-1);
	printf("\n\tNB	: [%d]\n", nb);
	return (0);
}
