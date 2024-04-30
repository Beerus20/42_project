#include "push_swap.h"

// void	ft_arrange(t_pile *pile);
// void	ft_reverse_arrange(t_pile *pile);
void	launch(t_pile *pile);

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;

	i = 0;
	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	launch(pile);
	// ft_printf("NB MOVE	: [%d]\n", ft_count_move(*pile->a, 3));
	// while (!ft_check_isalign(*pile->a))
	// 	ft_arrange(pile);
	ft_free_pile(pile);
	return (0);
}

void	launch(t_pile *pile)
{
	int	i;

	i = 0;
	while (i < 15 && !ft_check_isalign(*pile->a))
	{
		ft_move_to_a(pile);
		ft_action(pile, 0, 0);
		i++;
	}
}

// void	ft_arrange(t_pile *pile)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 3)
// 	{
// 		ft_action(pile, 0, 0, i);
// 		// ft_add_to_a(pile);
// 		i++;
// 	}
// }

// void	ft_reverse_arrange(t_pile *pile)
// {
// 	int	max_a;
// 	int	max_b;
// 	int	max;

// 	max_a = ft_get_max_value(*pile->a);
// 	max_b = ft_get_max_value(*pile->b);
// 	if (max_a > max_b)
// 		max = max_a;
// 	else
// 	{
// 		max = max_b;

// 	}
// 	if (*pile->b && max == (*(pile->b))->content)
// 		exec(pile, "rb");
// 	while (*pile->b)
// 	{
// 		// ft_add_to_a(pile);
// 		if ((*pile->ib->first) == max)
// 			exec(pile, "pa ra");
// 	}
// }

// void	ft_simulation(t_pile pile)
// {

// }
