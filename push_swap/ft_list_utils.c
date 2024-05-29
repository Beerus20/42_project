#include "push_swap.h"

int	ft_isbetween(int value, int a, int b)
{
	return (value >= a && value <= b);
}

t_list	*ft_move_to(t_list *pile, int value)
{
	if (pile && ft_search(pile, value) != -1)
	{
		while (pile->content != value)
			pile = pile->next;
		return (pile);
	}
	return (NULL);
}

void	ft_del_list_value(t_list **list, int value)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*to_free;

	prev = NULL;
	to_free = NULL;
	tmp = *list;
	while (tmp && tmp->content != value)
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

void	ft_add_list_value(t_list **list, int index, int value)
{
	int		i;
	t_list	*prev;
	t_list	*tmp;
	t_list	*iter;

	prev = NULL;
	tmp = NULL;
	iter = *list;
	while (i < index)
	{
		prev = iter;
		iter = iter->next;
		i++;
	}
	if (prev)
	{
		tmp = prev->next;
		prev->next = ft_init_list(value);
		prev->next->next = tmp;
	}
	else
		ft_add_front(list, ft_init_list(value));
}

void	ft_add_back_content(t_list **pile, int value)
{
	t_list	*tmp_list;
	t_list	*tmp;

	tmp = ft_init_list(-1);
	tmp_list = *pile;
	if (tmp_list)
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp->content = value;
		tmp_list->next = tmp;
	}
	else
	{
		tmp->content = value;
		*pile = tmp;
	}
}

void	ft_add_back(t_list **pile, t_list *new)
{
	t_list	*tmp_list;

	tmp_list = *pile;
	if (tmp_list)
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp_list->next = new;
	}
	else
		*pile = new;
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

void	ft_concat_list(t_list **a, t_list **b, t_list *s_a, t_list *s_b)
{
	t_list	*prev;
	t_list	*tmp;

	prev = NULL;
	tmp = *a;
	while (tmp && tmp != s_a)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	ft_free_list(tmp);
	if (prev)
		prev->next = *b;
	else
		*a = *b;
	prev = NULL;
	tmp = *b;
	while (tmp && tmp != s_b)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev->next)
		prev->next = NULL;
	ft_free_list(tmp);
}

t_list	*ft_copy_list(t_list *list)
{
	t_list	*r_value;

	r_value = NULL;
	while (list)
	{
		ft_add_back_content(&r_value, list->content);
		list = list->next;
	}
	return (r_value);
}