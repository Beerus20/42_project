#include "push_swap.h"

int	ft_check_isgreater(t_list **pile, t_ipile *ipile)
{
	t_list	*tmp;

	tmp = *pile;
	if (tmp->next)
	{
		tmp = tmp->next;
		while (tmp)
		{
			if (tmp->content > *(ipile->first))
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int	ft_check_isgreater_inv(t_list **pile, t_ipile *ipile)
{
	t_list	*tmp;
	int		*last;

	last = NULL;
	if (ipile->last)
		last = ipile->last;
	else if (ipile->second)
		last = ipile->second;
	else if (ipile->first)
		last = ipile->first;
	else
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (tmp->content < *last)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check(t_list *pile, int	argc)
{
	if (!pile)
		return (1);
	if (ft_check_alignement(pile, 0) == argc)
		return (1);
	return (0);
}

int	ft_check_alignement(t_list *pile, int direction)
{
	int	to_compare;

	to_compare = pile->content;
	if (pile->next)
	{
		pile = pile->next;
		while (pile)
		{
			if (!direction)
			{
				if (to_compare > pile->content)
					return (0);
			}
			else
			{
				if (to_compare < pile->content)
					return (0);
			}
			to_compare = pile->content;
			pile = pile->next;
		}
	}
	return (1);
}

int	ft_count_move(t_list **pile, t_ipile *ia, int len)
{
	
	return (0);
}

int	ft_search_position(t_list *pile, int value)
{
	int	i;
	int up_value;

	i = 0;
	up_value = 0;
	if (pile->next)
	{
		up_value = pile->content;
		pile = pile->next;
		while (pile)
		{
			if (up_value > value && value > pile->content)
				return (i);
			up_value = pile->content;
			pile = pile->next;
			i++;
		}
	}
	return (i);
}