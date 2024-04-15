#include <stdio.h>
#include <limits.h>
#include "includes/ft_printf.h"

int	ft_check(char c)
{
	int		i;
	char	*desc;

	i = 0;
	desc = "csduixX%";
	while (desc[i])
	{
		if (desc[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_get_with(char *str)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (!(str[i] >= '1' && str[i] <= '9') && !ft_check(str[i]))
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && !ft_check(str[i]))
	{
		width = (str[i] - 48) + (width * 10);
		i++;
	}
	return (width);
}

int	ft_get_precision(char *str)
{
	int	i;
	int	prec;

	i = 0;
	prec = 0;
	while (str[i++] != '.' && !ft_check(str[i]))
		;
	while ((str[i] >= '0' && str[i] <= '9') && !ft_check(str[i]))
	{
		prec = (str[i] - 48) + (prec * 10);
		i++;
	}
	return (prec);
}

int	main(void)
{
	int	nb;
	char	*test;

	nb = 2147483648;
	test = NULL;
	printf("%d\n", ft_get_with("0#- 20.5d"));
	printf("%d\n", ft_get_precision("0#- 20.5d"));
	// printf("NB	: %d\n", ft_printf("CPY: %u \n", LONG_MAX));
	// printf("NB	: %d\n", printf("ORG: %lu \n", LONG_MAX));
	return (0);
}
