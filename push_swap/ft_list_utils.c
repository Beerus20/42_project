#include "push_swap.h"

void	ft_del_list_value(t_list **list, int value)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*to_free;

	prev = NULL;
	to_free = NULL;
	tmp = *list;
	while (tmp->content != value)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	to_free = tmp;
	if (prev == NULL)
		*list = tmp->next;
	else
		prev->next = tmp->next;
	free(to_free);
}

int	ft_get_list_len(t_list *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

t_list	*ft_init_list(int value)
{
	t_list	*r_list;

	r_list = (t_list *)malloc(sizeof(t_list));
	if (!r_list)
		exit(1);
	r_list->content = value;
	r_list->next = NULL;
	return (r_list);
}

void	ft_add_front(t_list **pile, t_list *new)
{
	new->next = *pile;
	*pile = new;
}

void	ft_del_front(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	*pile = tmp->next;
	free(tmp);
}

void	ft_add_back(t_list **pile, t_list *new)
{
	t_list	*tmp_list;
	t_list	*tmp;

	tmp = ft_init_list(-1);
	tmp_list = *pile;
	if (tmp_list)
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp->content = new->content;
		tmp_list->next = tmp;
	}
	else
	{
		tmp->content = new->content;
		*pile = tmp;
	}
}

void	ft_pop(t_list **pile)
{
	t_list	*tmp;
	t_list	*to_free;
	int		len;

	if (*pile)
	{
		to_free = NULL;
		tmp = *pile;
		len = ft_get_list_len(*pile);
		if (len == 1)
		{
			free(*pile);
			*pile = NULL;
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
}
