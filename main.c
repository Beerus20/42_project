#include <stdio.h>
#include "./ft_printf/includes/ft_printf.h"

int	main(void)
{
	ft_printf("test %c%c%c*\n", '\0', '1', 1);
	/* printf("ORIGINAL	:\n");
	printf("[%c] [%d]\n", '\0', '\0');
	printf("[%c] [%d]\n", '1', '1');
	printf("[%c] [%d]\n\n", 1, 1); */
	//nb = printf("test	: %c %d %d %s %%\n", 't', 12, 45, "HELLO WORLD");
	//clearprintf("NB	: [%d]", nb);
	return (0);
}
