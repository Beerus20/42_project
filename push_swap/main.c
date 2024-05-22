#include "push_swap.h"

int	ft_count_nb(t_list *pile, int compare, int sup, int stop_nb)
{
	int	count;

	count = 0;
	while (pile && pile->content != stop_nb)
	{
		if (sup && pile->content > compare)
			count++;
		if (!sup && pile->content < compare)
			count++;
		pile = pile->next;
	}
	return (count);
}

void	ft_analysies(t_pile *pile, t_list *ref)
{
	ft_check_additional_ref(*pile->a, ref);
	ft_rectification_ref(*pile->a, ref);
	ft_action(pile, ref);
}

int	main(int argc, const char **argv)
{
	t_pile	*pile;
	t_list	*result;

	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	// ft_show(*pile);
	result = ft_get_max_increase(*pile->a);
	// ft_show_diff(pile, ref);
	// ft_show_pile(ref);
	ft_show_diff(*pile->a, result);
	// test(argc, argv);
	ft_analysies(pile, result);
	// result = ft_get_sub_list_sup(*pile->a, )
	ft_free_list(result);
	ft_free_pile(pile);
	return (0);
}
