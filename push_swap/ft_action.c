#include "push_swap.h"

int	ft_search(t_list *pile, int value)
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

int	ft_action(t_pile *pile, t_list *ref)
{
	t_list	*tmp;
	int		stop;
	int		i;

	i = 0;
	stop = ft_get_last(ref)->content;
	while (*pile->a && i++ < 100)
	{
			// ft_move_to_b(pile, ref);
			// ft_move_to_a(pile, ref);
		if (ft_search(ref, (*pile->a)->content) == -1)
			ft_action_to_b(pile, ref);
		else
			exec(pile, "ra");
	}
	return (0);
}
