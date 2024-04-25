# include <stdio.h>
#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_pile	*pile;
	// exec("sa sb pa pb ra rb");
	pile = ft_init_piles(argc, argv);
	ft_show(*pile);
	return (0);
}

