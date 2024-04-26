#include "push_swap.h"

void	ft_free(t_list **pile)
{
	t_list	*tmp;

	tmp = NULL;
	while (*pile)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		free(tmp);
	}
	free(pile);
}

void	ft_free_info(t_info *info)
{
	free(info->first);
	free(info->second);
	free(info->last);
	free(info->len);
	info->first = NULL;
	info->second = NULL;
	info->last = NULL;
	info->len = NULL;
}

void	ft_free_pile(t_pile *pile)
{
	ft_free(pile->a);
	ft_free(pile->b);
	ft_free_info(pile->ia);
	ft_free_info(pile->ib);
	free(pile->ia);
	free(pile->ib);
	free(pile);
}
