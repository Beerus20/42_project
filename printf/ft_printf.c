#include "printf.h"

void	test(int nb, va_list list)
{
	int	tmp;
	va_list	args;

	args = list;
	va_start(args, nb);
	while (nb)
	{
		tmp = va_arg(args, int);
		printf("value : [%d]\n", tmp);
		nb--;
	}
	va_end(args);
}

int	ft_printf(const char *str, int test, ...)
{
	va_list	arg;
	int	nb_descriptor;
	int	tmp;
	int	i;

	nb_descriptor = ft_count_char(str, '%');
	test(nb_descriptor, arg);
	return (0);
}

int	main(void)
{
	ft_printf("simple \ntest %[i][s] % % % %", 5, 12, 35, 65, 78, 45);
	return (0);
}
