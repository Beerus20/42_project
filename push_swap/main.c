#include "push_swap.h"

int	ft_count_nb(t_list *pile, int compare, int sup, int stop_nb)
{
	int	count;

	count = 0;
	while (pile && pile->content != stop_nb)
	{
		if (sup && pile->content > compare)
			count++;
		if (!sup && pile->content < compare)
			count++;
		pile = pile->next;
	}
	return (count);
}

t_list	*ft_move_to(t_list *pile, int value)
{
	if (pile && ft_search(pile, value))
	{
		while (pile->content != value)
			pile = pile->next;
		return (pile);
	}
	return (NULL);
}

t_list	*ft_get_sub_list_inf(t_list *pile, int begin, int end, int value)
{
	t_list	*r_value;
	t_list	*tmp;

	r_value = ft_init_list(-1);
	tmp = r_value;
	if (ft_get_index(pile, begin) > ft_get_index(pile, end))
		return (r_value);
	pile = ft_move_to(pile, begin);
	while (pile && pile->content != end)
	{
		if (pile->content < value)
		{
			tmp->content = pile->content;
			tmp->next = ft_init_list(-1);
			tmp = tmp->next;
		}
		pile = pile->next;
	}
	if (pile && pile->content == end)
		tmp->content = end;
	return (r_value);
}

t_list	*ft_get_sub_list_sup(t_list *pile, int begin, int end, int value)
{
	t_list	*r_value;
	t_list	*tmp;

	r_value = ft_init_list(-1);
	tmp = r_value;
	if (ft_get_index(pile, begin) > ft_get_index(pile, end))
		return (r_value);
	pile = ft_move_to(pile, begin);
	while (pile && pile->content != end)
	{
		if (pile->content > value)
		{
			tmp->content = pile->content;
			tmp->next = ft_init_list(-1);
			tmp = tmp->next;
		}
		pile = pile->next;
	}
	if (pile && pile->content == end)
		tmp->content = end;
	return (r_value);
}

void	ft_ajust(t_pile *pile, t_list *ref)
{
	t_list	*list;
	t_list	*tmp_up;
	t_list	*tmp_down;
	int		ref_last;

	list = *pile->a;
	ref_last = ft_get_last(ref)->content;
	tmp_up = ft_get_max_increase(ft_get_sub_list_sup(list, list->content, ref->content, ref_last));
	tmp_down = ft_get_max_increase(ft_get_sub_list_sup(list, ref_last, pile->ia->last, ref->content));
	ft_show_pile(tmp_up);
	while (pile->ia->last != ref_last)
	{
		if (pile->ia->last < ref->content)
		{
			ft_add_front(&ref, ft_init_list(pile->ia->last));
			exec(pile, "rra");
		}
		else
			exec(pile, "rra pb");
	}
	while (pile->ia->first != ref->content)
	{
		if (tmp_up && tmp_up->content != -1 && pile->ia->first == tmp_up->content)
		{
			ft_add_back(&ref, ft_init_list(pile->ia->first));
			exec(pile, "ra");
			tmp_up = tmp_up->next;
		}
		else
			exec(pile, "pb");
	}
}

void	ft_analysies(t_pile *pile, t_list *ref)
{
	t_list	*first;

	first = NULL;
	ft_ajust(pile, ref);
	// if (*pile->b)
	// {
	// 	first = ft_get_sub_list_inf(*pile->b, pile->ib->first, pile->ib->last, ref->content);
	// 	if (first->content != -1)
	// 	{
	// 		while (first->content != -1)
	// 		{
	// 			ft_move_a(pile, first);
	// 			first = ft_get_sub_list_inf(*pile->b, pile->ib->first, pile->ib->last, ref->content);
	// 		}
	// 	}
	// }
	ft_action(pile, ref);
	// ft_show(*pile);
}

// void	launch(t_pile *pile, t_list *ref)
// {

// }

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;
	t_list	*result;

	i = 0;
	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	ft_show(*pile);
	result = ft_get_max_increase(*pile->a);
	ft_show_diff(*pile->a, result);
	// *pile->a = ft_get_sub_list_sup(*pile->a, 15, 7, -1);
	ft_analysies(pile, result);
	// result = ft_get_sub_list_sup(*pile->a, )
	ft_free_list(result);
	ft_free_pile(pile);
	return (0);
}
