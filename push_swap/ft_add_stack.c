#include "push_swap.h"

void	ft_add_to_a(t_pile *pile)
{
	int	behind;
	int	value;

	behind = ft_get_position(*pile->a, pile->ib->first, 1);
	value = ft_get_value(*pile->a, behind);
	while (pile->ia->first != value)
	{
		if (behind >= pile->ib->len / 2)
			exec(pile, "rra");
		else
			exec(pile, "ra");
	}
	exec(pile, "pa");
}

void	ft_add_to_b(t_pile *pile)
{
	int	front;
	int	value;

	if (*pile->b == NULL)
	{
		exec(pile, "pb");
		return ;
	}
	front = ft_get_position(*pile->b, pile->ia->first, 0);
	value = ft_get_value(*pile->b, front);
	while (pile->ib->first != value)
	{
		if (front >= pile->ib->len / 2)
			exec(pile, "rrb");
		else
			exec(pile, "rb");
	}
	exec(pile, "pb");
}

// void	ft_add_stack(t_pile *pile)
// {
// 	int	front_b;
// 	int	behind_a;

// 	front_b = ft_get_position(*pile->b, pile->ia->first, 0);
// 	behind_a = ft_get_position(*pile->a, pile->ib->first, 1);
// 	if (front_b > pile->ib->len / 2)
// 		front_b = pile->ib->len - front_b;
// 	if (behind_a > pile->ia->len / 2)
// 		behind_a = pile->ia->len - behind_a;
// 	// ft_printf("VALUE	: \nFRONT	: [%d]\nBEHIND	: [%d]\n\n", front_b, behind_a);
// 	if (front_b < behind_a)
// 		ft_add_to_b(pile);
// 	else
// 		ft_add_to_a(pile);
// }