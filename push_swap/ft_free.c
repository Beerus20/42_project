#include "push_swap.h"

void	ft_free_list(t_list *pile)
{
	t_list	*tmp;

	tmp = NULL;
	while (pile)
	{
		tmp = pile;
		pile = pile->next;
		free(tmp);
	}
}

void	ft_free(t_list **pile)
{
	ft_free_list(*pile);
	free(pile);
}

void	ft_free_pile(t_pile *pile)
{
	ft_free(pile->a);
	ft_free(pile->b);
	free(pile->ia);
	free(pile->ib);
	free(pile);
}
