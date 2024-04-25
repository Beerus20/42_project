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
}
