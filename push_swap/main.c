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
<<<<<<< HEAD
	// ft_ajust(pile, ref);
	// ft_move_to_b(pile, ref);
	// ft_move_to_a(pile, ref);
	ft_action(pile, ref);
}

// void	launch(t_pile *pile, t_list *ref)
// {

// }

void	test(int argc, const char **argv)
{
	t_pile	*pile;
	t_list	*result;

	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	ft_show(*pile);
	result = ft_init_list(3);
	ft_add_back(&result, ft_init_list(7));
	ft_add_back(&result, ft_init_list(10));
	ft_show_diff(*pile->a, result);
	ft_move_to_b(pile, result);
	ft_move_to_a(pile, result);
	// ft_show(*pile);
	// ft_printf("SUB	:\n");
	// ft_show_pile(ft_get_section(*pile->a, result, ft_get_index(result, 3)));
	// ft_show_pile(ft_get_section(*pile->a, result, ft_get_index(result, 7)));
	// ft_get_classements(*pile->a, result);
}

=======
	ft_check_additional_ref(*pile->a, ref);
	ft_rectification_ref(*pile->a, ref);
	ft_action(pile, ref);
}

>>>>>>> debug
int	main(int argc, const char **argv)
{
	t_pile	*pile;
	t_list	*result;

	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	// ft_show(*pile);
	result = ft_get_max_increase(*pile->a);
<<<<<<< HEAD
	// ft_show_diff(*pile->a, result);
=======
	// ft_show_diff(pile, ref);
	// ft_show_pile(ref);
	ft_show_diff(*pile->a, result);
>>>>>>> debug
	// test(argc, argv);
	ft_analysies(pile, result);
	// result = ft_get_sub_list_sup(*pile->a, )
	ft_free_list(result);
	ft_free_pile(pile);
	return (0);
}
