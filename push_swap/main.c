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

// 37 18 20 44 48 88 76 38 56 79 8 86 58 80 29 13 70 59 69 45 46 72 53 24 42 93 51 60 40 39 35 61 33 6 91 68 82 14 28 78 32 16 9 96 47 94 75 10 7 57 23 41 74 22 50 49 31 71 3 5 65 52 89 62 64 66 12 15 34 21 95 99 36 83 19 84 30 1 25 87 43 100 11 77 55 73 54 92 4 67 26 2 85 98 17 90 97 81 63 27

