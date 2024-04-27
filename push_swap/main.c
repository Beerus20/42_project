#include "push_swap.h"

// void	ft_arrange_2(t_pile *pile);
// int		ft_specific_case(t_pile *pile);
void	launch(t_pile *pile);

int	main(int argc, const char **argv)
{
	t_pile	*pile;

	pile = ft_init_piles(argc, argv);
	ft_action(pile, 0, 0, 1);
	// ft_printf("POSITION	: [%d]\n", ft_get_position(*(pile->a), 5));
	// ft_printf("INDEX	: [%d]\n", ft_get_index(*(pile->a), 5));
	// launch(pile);
	ft_free_pile(pile);
	return (0);
}

void	launch(t_pile *pile)
{
	// ft_check_percent("INCREASE", pile, ft_check_increas, 0);
	// ft_check_percent("DECREASE", pile, ft_check_decreas, 0);
	// exec(pile, "rra");
	// ft_check_percent("INCREASE", pile, ft_check_increas, 0);
	// ft_check_percent("DECREASE", pile, ft_check_decreas, 0);
}

// int	ft_specific_case(t_pile *pile)
// {
// 	if ((*(pile->ia->len) == 2))
// 	{
// 		ft_arrange_2(pile);
// 		return (0);
// 	}
// 	if ((*(pile->ia->len) == 3))
// 	{
// 		if (ft_check_isbigger(*(pile->a), *(pile->ia->first)) && ft_check_isalign((*(pile->a))->next))
// 			exec(pile, "ra");
// 		return (0);
// 	}
// 	if ((*(pile->ia->len) == 4))
// 	{

// 	}
// }

// void	ft_arrange_2(t_pile *pile)
// {
// 	if ((*(pile->ia->first)) > (*(pile->ia->second)))
// 		exec(pile, "ra");
// }

// void	ft_arrange_3(t_pile *pile)
// {
// 	// if ((*(pile->ia->first)) > (*(pile->ia->second)))
// }

// void	ft_simulation(t_pile pile)
// {

// }
