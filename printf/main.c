#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int	nb;
	char	*text;
	char	*test;

	test = NULL;
	nb = 0;
	printf("NB : ");
	scanf("%d", &nb);
	text = "result	: [%-10u]\n";
	// text = "result : [%10c %.2s %20p %d %i %u %#20x %#20X %%] \n";
	// printf("%d\n", ft_get_with("0#- 20.5d"));
	// printf("%d\n", ft_get_precision("0#- 20.5d"));
	printf("NB	: %d\n", ft_printf(text, nb));
	printf("NB	: %d\n", printf(text, nb));
	// printf("NB	: %d\n", ft_printf(text, 'c', test, test, nb, nb, nb, nb, nb));
	// printf("NB	: %d\n", printf(text, 'c', test, test, nb, nb, nb, nb, nb));
	// printf("test	: [%20p]\n", test);
	return (0);
}
