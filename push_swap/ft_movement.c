#include "push_swap.h"

void	ft_swap(t_list **pile, t_ipile *ipile)
{
	t_list	*tmp;

	tmp = (*pile)->next;
	(*pile)->next = tmp->next;
	tmp->next = (*pile);
	*pile = tmp;
	ft_free_info(ipile);
	ft_get_info(pile, ipile);
}

void	ft_push(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib)
{
	t_list	*tmp;

	if (*pile_a)
	{
		tmp = *pile_a;
		*pile_a = tmp->next;
		tmp->next = *pile_b;
		*pile_b = tmp;
		ft_free_info(ia);
		ft_free_info(ib);
		ft_get_info(pile_a, ia);
		ft_get_info(pile_b, ib);
	}
}

void	ft_rotate(t_list **pile, t_ipile *ipile)
{
	t_list	*tmp;
	t_list	*end;

	tmp = *pile;
	end = tmp;
	if (tmp->next)
	{
		*pile = tmp->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = end;
		tmp->next->next = NULL;
		ft_free_info(ipile);
		ft_get_info(pile, ipile);
	}
}

void	ft_rev_rotate(t_list **pile, t_ipile *ipile)
{
	t_list	*tmp;
	t_list	*start;

	tmp = *pile;
	if (tmp->next)
	{
		while (tmp->next)
		{
			if (!tmp->next->next)
			{
				start = tmp->next;
				tmp->next = NULL;
				break ;
			}
			tmp = tmp->next;
		}
		if (start)
		{
			start->next = *pile;
			*pile = start;
		}
		ft_free_info(ipile);
		ft_get_info(pile, ipile);
	}
}
