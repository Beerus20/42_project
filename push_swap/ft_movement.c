#include "push_swap.h"

void	ft_swap(t_list **pile)
{
	t_list	*tmp;

	if (*pile)
	{
		tmp = (*pile)->next;
		(*pile)->next = tmp->next;
		tmp->next = (*pile);
		*pile = tmp;
	}
}

void	ft_push(t_pile *pile, int inv)
{
	t_list	*tmp;

	if (inv && *(pile->b))
	{
		tmp = *(pile->b);
		*(pile->b) = tmp->next;
		tmp->next = *(pile->a);
		*(pile->a) = tmp;
	}
	if (!inv && *(pile->a))
	{
		tmp = *(pile->a);
		*(pile->a) = tmp->next;
		tmp->next = *(pile->b);
		*(pile->b) = tmp;
	}
}

void	ft_rotate(t_list **pile)
{
	t_list	*tmp;
	t_list	*end;

	tmp = *pile;
	end = tmp;
	if (tmp)
	{
		if (tmp->next)
		{
			*pile = tmp->next;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = end;
			tmp->next->next = NULL;
		}
	}
}

void	ft_rev_rotate(t_list **pile)
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
	}
}
