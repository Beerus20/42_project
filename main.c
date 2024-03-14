#include <stdio.h>
#include "./printf/includes/ft_printf.h"

int	main(void)
{
	int nb;

	nb = ft_printf("test	: %12c %12d %18d %#12.3s %%\n", 't', 12, 45, "HELLO WORLD");
	printf("NB	: [%d]", nb);
	//nb = printf("test	: %c %d %d %s %%\n", 't', 12, 45, "HELLO WORLD");
	//clearprintf("NB	: [%d]", nb);
	return (0);
}
