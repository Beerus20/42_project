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

int	ft_get_position(t_list *pile, int value)
{
	int	number;
	int	position;
	int	i;

	position = 0;
	i = 0;
	number = ft_get_max_value(pile);
	while (pile)
	{
		// ft_printf("CONTENT		: [%d]\nNUMBER		: [%d]\nVALUE		: [%d]\nPOSITION	: [%d]\n\n", pile->content, number, value, position);
		if (pile->content > value)
		{
			if (pile->content <= number)
			{
				number = pile->content;
				position = i;
			}
		}
		if (pile->content != value)
			i++;
		pile = pile->next;
	}
	return (position);
}

int	ft_get_position_inv(t_list *pile, int value)
{
	int	number;
	int	position;
	int	i;

	position = 0;
	i = 0;
	number = ft_get_min_value(pile);
	while (pile)
	{
		if (pile->content > value)
		{
			i++;
			if (pile->content >= number)
			{
				number = pile->content;
				position = i;
			}
		}
		pile = pile->next;
	}
	return (position);
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