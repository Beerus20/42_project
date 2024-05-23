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

void	ft_analysies(t_pile *pile, t_pile *ref)
{
	ft_transform_value(pile);
	*ref->a = ft_get_max_increase(*pile->a);
	// ft_add_back_content(ref->a, 10);
	// ft_add_back_content(ref->a, 20);
	// ft_add_back_content(ref->a, 30);
	// ft_add_back_content(ref->a, 40);
	// ft_add_back_content(ref->a, 50);
	// ft_add_back_content(ref->a, 60);
	// ft_add_back_content(ref->a, 70);
	// ft_add_back_content(ref->a, 80);
	// ft_add_back_content(ref->a, 90);
	ft_get_info(ref->a, ref->ia);
	ft_show_diff(*pile->a, *ref->a);

	ft_check_additional_ref(*pile->a, *ref->a);
	ft_rectification_ref(*pile->a, *ref->a);
	ft_action(pile, ref);
}

void	test(t_pile *pile)
{
	t_list	*ref;

	ref = NULL;
	ft_add_back_content(&ref, 2);
	ft_add_back_content(&ref, 6);
	ft_add_back_content(&ref, 8);
	ft_show_pile(ft_get_extra(*pile->a, ref));
	ft_printf("COUNT RESULT	: [%d]\n", ft_count_move(*pile->a, ref, 10));
}

int	main(int argc, const char **argv)
{
	t_pile	*pile;
	t_pile	*ref;

	pile = ft_init();
	ref = ft_init();
	ft_init_pile(argc, argv, pile->a);
	ft_get_info(pile->a, pile->ia);
	ft_get_info(pile->b, pile->ib);

	// test(pile);
	// ft_printf("test	: [%d]\n", (-2) - (-1));
	ft_analysies(pile, ref);
	ft_free_pile(ref);
	ft_free_pile(pile);
	return (0);
}

// 37 18 20 44 48 88 76 38 56 79 8 86 58 80 29 13 70 59 69 45 46 72 53 24 42 93 51 60 40 39 35 61 33 6 91 68 82 14 28 78 32 16 9 96 47 94 75 10 7 57 23 41 74 22 50 49 31 71 3 5 65 52 89 62 64 66 12 15 34 21 95 99 36 83 19 84 30 1 25 87 43 100 11 77 55 73 54 92 4 67 26 2 85 98 17 90 97 81 63 27

// 48 98 86 74 41 81 65 18 35 87 64 6 85 37 97 51 8 79 23 66 33 47 93 39 17 19 54 15 67 7 53 100 25 61 5 43 34 70 62 3 2 92 9 90 44 59 38 24 75 1 91 72 80 10 63 11 94 29 88 42 69 60 4 99 77 46 22 73 89 71 45 84 21 58 83 30 28 76 56 57 55 32 78 14 20 16 96 49 95 12 13 31 82 50 40 27 36 26 68 52