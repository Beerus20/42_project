#include "push_swap.h"

int	ft_check_increas(t_list *pile)
{
	int		i;
	int		to_compare;
	t_list	*tmp;

	i = 1;
	to_compare = 0;
	tmp = pile;
	if (tmp)
	{
		to_compare = tmp->content;
		if (tmp->next)
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
