#include "../push_swap.h"

void	ft_sa(t_list **pile)
{
	t_list	*tmp;

	tmp = (*pile)->next;
	(*pile)->next = tmp->next;
	tmp->next = (*pile);
	*pile = tmp;
}
// l1 -> l2 -> l3