#include "push_swap.h"

int	ft_arrange_pile(t_list **pile, t_ipile *ipile)
{
	if (*(ipile->first) < *(ipile->last) && *(ipile->second) > *(ipile->last))
	{
		ft_printf("\033[0;31TEST\n\n");
		ft_rev_rotate(pile, ipile);
		ft_swap(pile, ipile);
		return (1);
	}
	return (0);
}

int	ft_action_isgreater(t_list **pile, t_ipile *ipile)
{
	int	is_applied;

	is_applied = 0;
	if (ft_check_isgreater(pile, ipile))
	{
		ft_rotate(pile, ipile);
		is_applied = 1;
	}
	if (ft_check_isgreater_inv(pile, ipile))
	{
		ft_rev_rotate(pile, ipile);
		is_applied = 1;
	}
	return (is_applied);
}

int	ft_is_both_aligned(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib)
{
	if (ft_check_alignement(*pile_a, 0) && ft_check_alignement(*pile_b, 1))
	{
		// if (ia->first > ib->first)
		// {
			while (*(ib->len))
				ft_push(pile_b, pile_a, ib, ia);
			return (1);
		// }
	}
	return (0);
}