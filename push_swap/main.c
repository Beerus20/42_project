#include "push_swap.h"

// void	ft_arrange(t_pile *pile);
// void	ft_reverse_arrange(t_pile *pile);
void	launch(t_pile *pile, int len);

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;

	i = 0;
	pile = ft_init_piles(argc, argv);
	// ft_show(*pile);
	ft_transform_value(pile);
	launch(pile, argc - 1);
	// ft_printf("POSITION OF	: \n");
	// ft_printf("-IN FRONT	: [%d]\n", ft_get_position(*pile->a, 1, 0));
	// ft_printf("-POSITION	: [%d]\n", ft_position_of(*pile->a, 1));
	// ft_printf("-BEHIND		: [%d]\n", ft_get_position(*pile->a, 1, 1));
	// while (!ft_check_isalign(*pile->a))
	// 	ft_arrange(pile);
	ft_free_pile(pile);
	return (0);
}

int	verify(t_list *pile, int min, int max)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->content >= min && tmp->content < max)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


void	launch(t_pile *pile, int len)
{
	int	id_max;
	int	max;

	while (verify(*pile->a, 0, 20))
		ft_action(pile, 0, 20);

	while (verify(*pile->a, 20, 40))
		ft_action(pile, 20, 40);

	while (verify(*pile->a, 40, 60))
		ft_action(pile, 40, 60);

	while (verify(*pile->a, 60, 80))
		ft_action(pile, 60, 80);

	while (verify(*pile->a, 80, 95))
		ft_action(pile, 80, 95);

	// max = ft_get_max_value(*pile->a);
	// id_max = ft_get_index(*pile->a, max);
	// if (id_max > *pile->ia->len / 2)
	// {
	// 	while (*pile->ia->first != max)
	// 		exec(pile, "rra");
	// }
	// else
	// {
	// 	while (*pile->ia->first != max)
	// 		exec(pile, "ra");
	// }
	// // // ft_arrange(pile);
	// while (*pile->ib->len != 0)
	// 	ft_add_to_a(pile);
	// ft_arrange(pile);
}


// while (verify(*pile->a, 0, 20))
// 		ft_action(pile, 0, 20);

// 	while (verify(*pile->a, 20, 40))
// 		ft_action(pile, 20, 40);

// 	while (verify(*pile->a, 40, 60))
// 		ft_action(pile, 40, 60);

// 	while (verify(*pile->a, 60, 80))
// 		ft_action(pile, 60, 80);

// 	while (verify(*pile->a, 80, 95))
// 		ft_action(pile, 80, 95);