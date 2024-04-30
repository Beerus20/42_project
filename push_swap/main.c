#include "push_swap.h"

void	ft_arrange(t_pile *pile);
void	ft_reverse_arrange(t_pile *pile);
void	launch(t_pile *pile);

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;

	i = 0;
	pile = ft_init_piles(argc, argv);
	while (!ft_check_isalign(*pile->a))
		ft_arrange(pile);
	// while (ft_check_isalign(*pile->a) != (argc - 1))
	// 	ft_reverse_arrange(pile);
	// ft_action(pile, 0, 0, 1);
	// ft_printf("POSITION	: [%d]\n", ft_get_position_inv(*(pile->a), 7));
	// ft_printf("INDEX	: [%d]\n", ft_get_index(*(pile->a), 5));
	// launch(pile);
	ft_free_pile(pile);
	return (0);
}

void	launch(t_pile *pile)
{

}

void	ft_arrange(t_pile *pile)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_action(pile, 0, 0, i);
		ft_add_to_a(pile);
		i++;
	}
}

void	ft_reverse_arrange(t_pile *pile)
{
	int	max_a;
	int	max_b;
	int	max;

	max_a = ft_get_max_value(*pile->a);
	max_b = ft_get_max_value(*pile->b);
	if (max_a > max_b)
		max = max_a;
	else
	{
		max = max_b;

	}
	if (*pile->b && max == (*(pile->b))->content)
		exec(pile, "rb");
	while (*pile->b)
	{
		ft_add_to_a(pile);
		if ((*pile->ib->first) == max)
			exec(pile, "pa ra");
	}
}

// void	ft_simulation(t_pile pile)
// {

// }
