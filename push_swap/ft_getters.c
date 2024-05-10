#include "push_swap.h"

int	ft_get_min_value(t_list *pile)
{
	int	max;

	max = 0;
	if (pile)
		max = pile->content;
	while (pile)
	{
		if (pile->content < max)
			max = pile->content;
		pile = pile->next;
	}
	return (max);
}

int	ft_get_max_value(t_list *pile)
{
	int	max;

	max = 0;
	if (pile)
		max = pile->content;
	while (pile)
	{
		if (pile->content > max)
			max = pile->content;
		pile = pile->next;
	}
	return (max);
}

int	ft_get_index(t_list *pile, int value)
{
	int	i;

	i = 0;
	while (pile)
	{
		if (pile->content == value)
			return (i);
		i++;
		pile = pile->next;
	}
	return (-1);
}

int	ft_get_value(t_list *pile, int index)
{
	int	i;

	i = 0;
	while (pile)
	{
		if (i == index)
			return (pile->content);
		i++;
		pile = pile->next;
	}
	return (-1);
}

int	ft_get_pile_len(t_list *pile)
{
	t_list	*tmp;
	int		r_len;

	r_len = 0;
	tmp = pile;
	while (tmp)
	{
		r_len++;
		tmp = tmp->next;
	}
	return (r_len);
}
