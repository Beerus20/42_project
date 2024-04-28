#include "push_swap.h"

void	ft_arrange(t_pile *pile);
void	launch(t_pile *pile);

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;

	i = 0;
	pile = ft_init_piles(argc, argv);
	// while (i < 4)
	// {
	// 	ft_arrange(pile);
	// 	i++;
	// }
	// ft_action(pile, 0, 0, 1);
	ft_printf("POSITION	: [%d]\n", ft_get_position(*(pile->a), 2));
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
		i++;
	}
}

// void	ft_simulation(t_pile pile)
// {

// }
