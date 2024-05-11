#include "push_swap.h"

void	ft_add_back(t_list *pile, t_list *new)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		exit(1);
	tmp->content = -1;
	tmp->next = NULL;
	if (pile)
	{
		while (pile->next)
			pile = pile->next;
		tmp->content = new->content;
		pile->next = tmp;
	}
	else
	{
		tmp->content = new->content;
		pile = tmp;
	}
}

void	ft_pop(t_list *pile)
{
	t_list	*tmp;
	t_list	*to_free;
	int		len;

	ft_printf("POP called...\n");
	to_free = NULL;
	tmp = pile;
	len = ft_get_pile_len(pile);
	if (len == 1)
	{
		free(tmp);
		tmp = NULL;
	}
	if (len > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		to_free = tmp->next;
		tmp->next = NULL;
		free(to_free);
	}
}
