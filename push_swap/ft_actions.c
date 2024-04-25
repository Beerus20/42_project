#include "push_swap.h"

int	ft_arrange_pile(t_list **pile, t_ipile *ipile)
{
	if (*(ipile->first) < *(ipile->last) && *(ipile->second) > *(ipile->last))
	{
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
	if (ft_check_isgreater_inv(pile, ipile))
	{
		ft_rev_rotate(pile, ipile);
		is_applied = 1;
	}
	if (ft_check_isgreater(pile, ipile))
	{
		ft_rotate(pile, ipile);
		is_applied = 1;
	}
	return (is_applied);
}

int	ft_is_both_aligned(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib)
{
	if (ft_check_alignement(*pile_a, 0) && ft_check_alignement(*pile_b, 1))
	{
		if (*(ia->first) > *(ib->first))
		{
			while (*(ib->len))
				ft_push(pile_b, pile_a, ib, ia);
			return (1);
		}
		else
		{
			while (*(ib->len))
			{
				if (*(ia->first) < *(ib->first))
				{
					ft_push(pile_b, pile_a, ib, ia);
					ft_swap(pile_a, ia);
				}
				else
					ft_push(pile_b, pile_a, ib, ia);
			}
		}
	}
	return (0);
}

int	ft_add_in_position(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib)
{
	int	*is_moveless;
	int	value;
	int	position;

	position = 0;
	is_moveless = ft_count_move(pile_b, ia, ib);
	value = *(ia->first);
	// ft_printf("MOVE	:\nINDEX	: [%d]\nNB	: [%d]\n\n", is_moveless[0], is_moveless[1]);
	if (is_moveless[0] == 1)
		value = *(ia->second);
	if (is_moveless[0] == 2)
		value = *(ia->last);
	position = ft_search_position(*pile_b, value);
	if (position <= (*(ib->len) / 2))
	{
		position = is_moveless[1];
		while (position)
		{
			ft_rev_rotate(pile_b, ib);
			position--;
		}
	}
	else
	{
		position = is_moveless[1];
		ft_printf("\033[0;33mTAFIDITRA ATO \n");
		while (position)
		{
			ft_rotate(pile_b, ib);
			position--;
		}
	}
	if (is_moveless[0] == 1)
		ft_swap(pile_a, ia);
	if (is_moveless[0] == 2)
		ft_rev_rotate(pile_a, ia);
	ft_push(pile_a, pile_b, ia, ib);
	free(is_moveless);
	return (1);
}
