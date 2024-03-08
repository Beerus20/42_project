#include <stdio.h>
#include "./printf/includes/ft_printf.h"

int	main(void)
{
	printf("\nADD	 	: [%.2f]\n", 12.58);
	ft_printf("\nCPY 		: [%s] [%d]\n", "HELLO", 52);
	//ft_decimal_to_str(10.052);
	return (0);
}