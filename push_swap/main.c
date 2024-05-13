#include "push_swap.h"

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;
	t_list	*result;

	i = 0;
	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	ft_show(*pile);
	// ft_show_pile(*pile->a);
	// ft_upper_nb(*pile->a, *pile->ia->first);
	// result = ft_analysies(pile);
	result = ft_get_increase_list(*pile->a);
	ft_show_diff(*pile->a, result);
	// ft_printf("BEGIN	: [%d]\n", ft_check_begin_max_increase(*pile->a));
	// ft_show_diff(*pile->a, result);
	// ft_show_pile(*pile->a);
	ft_free_list(result);
	ft_free_pile(pile);
	return (0);
}
