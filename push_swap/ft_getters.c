#include "push_swap.h"

int	ft_get_position(t_list *pile, int value)
{
	int	number;
	int	position;
	int	i;

	position = 0;
	i = 0;
	number = pile->content;
	while (pile)
	{
		// ft_printf("CONTENT		: [%d]\nNUMBER		: [%d]\nVALUE		: [%d]\nPOSITION	: [%d]\n\n", pile->content, number, value, position);
		if (pile->content > value)
		{
			if (pile->content < number)
			{
				number = pile->content;
				position = i;
			}
		}
		i++;
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
