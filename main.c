#include <stdio.h>
#include "./ft_printf/includes/ft_printf.h"

int	main(void)
{
	int	nb;

	//nb = ft_printf("%------21p yeah i'm %p running out %--p of ideas\n", (void *) 13, (void *) 65, (void *)-1);
	nb = ft_printf("%------21p yeah i'm %p running out %--p of ideas\n", (void *) 13, (void *) 65, (void *) -1);
	printf("NB	: [%d]\n", nb);
	nb = printf("%-21p yeah i'm %p running out %-p of ideas\n", (void *) 13, (void *) 65, (void *) -1);
	printf("NB	: [%d]\n", nb);
	//printf("[%-20d]\n", nb);
	//printf("[%12x]\n", 45);
	//printf("[%s]\n", "test.");
	/* printf("ORIGINAL	:\n");
	printf("[%c] [%d]\n", '\0', '\0');
	printf("[%c] [%d]\n", '1', '1');
	printf("[%c] [%d]\n\n", 1, 1); */
	//nb = printf("test	: %c %d %d %s %%\n", 't', 12, 45, "HELLO WORLD");
	//clearprintf("NB	: [%d]", nb);
	return (0);
}
