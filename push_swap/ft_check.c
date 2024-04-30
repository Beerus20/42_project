#include "push_swap.h"

int	ft_check_increas(t_list *pile)
{
	int		i;
	int		to_compare;
	t_list	*tmp;

	i = 0;
	to_compare = 0;
	tmp = pile;
	if (tmp)
	{
		to_compare = tmp->content;
		if (tmp->next && ++i)
		{
			tmp = tmp->next;
			while (tmp)
			{
				if (to_compare < tmp->content)
					i++;
				else
					return (i);
				to_compare = tmp->content;
				tmp = tmp->next;
			}
		}
	}
	return (i);
}

int	ft_check_decreas(t_list *pile)
{
	int		i;
	int		to_compare;
	t_list	*tmp;

	i = 0;
	to_compare = 0;
	tmp = pile;
	if (tmp)
	{
		to_compare = tmp->content;
		if (tmp->next && ++i)
		{
			tmp = tmp->next;
			while (tmp)
			{
				if (to_compare > tmp->content)
					i++;
				else
					return (i);
				to_compare = tmp->content;
				tmp = tmp->next;
			}
		}
	}
	return (i);
}

int	ft_check_isbigger(t_list *pile, int nb)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->content > nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_issmaller(t_list *pile, int nb)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->content < nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_isalign(t_list *pile)
{
	t_list	*tmp;
	int		i;
	int		to_compare;

	i = 1;
	tmp = pile;
	to_compare = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (to_compare > tmp->content)
			return (0);
		to_compare = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_check_percent(t_pile *pile, int (*function)(t_list *), int index)
{
	int	p_a;
	int	p_b;

	p_a = function(*(pile->a));
	p_b = function(*(pile->b));
	if (!index)
		return ((int )((p_a * 100) / (*(pile->ia)->len)));
	else
		return ((int )((p_b * 100) / (*(pile->ib)->len)));
	return (0);
}
