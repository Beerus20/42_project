#include "push_swap.h"

int	ft_check_additional_ref(t_list *pile, t_list *ref)
{
	t_list	*list;
	t_list	*tmp;
	t_list	*add_ref;
	int		last;
	int		len;

	len = ft_get_list_len(pile);
	list = ft_sub_list(pile, pile->content, ref->content);
	last = ft_get_last(ref)->content;
	tmp = ft_sub_list_between(list, last, len - 1);
	add_ref = ft_get_max_increase(tmp);
	ft_free_list(tmp);
	tmp = ft_move_to(ref, last);
	ft_free_list(list);
	if (add_ref)
	{
		tmp->next = add_ref;
		return (1);
	}
	return (0);
}

int	ft_rectification_ref(t_list	*pile, t_list *ref)
{
	t_list	*list;
	t_list	*max_increase;
	t_list	*tmp;
	int		len;
	int		i;

	i = 0;
	list = ft_sub_list(pile, pile->content, ref->content);
	max_increase = ft_get_max_increase(list);
	ft_free_list(list);
	len = ft_get_list_len(max_increase);
	tmp = ref;
	while (len && tmp && tmp->content < max_increase->content)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp && ft_get_list_len(ref) < len + i)
	{
		ft_concat_list(&ref, &max_increase, tmp, NULL);
		return (1);
	}
	ft_free_list(max_increase);
	return (0);
}

void	ft_get_extra(t_list *pile, t_list *ref, t_list **up, t_list **down)
{
	t_list	*tmp;

	tmp = NULL;
	ft_add_back(up, ft_get_portion(pile, ref));
	while (pile)
	{
		if (ft_search(ref, pile->content) != -1)
			tmp = pile;
		pile = pile->next;
	}
	if (tmp->next)
		ft_add_back(down, ft_get_portion(tmp->next, ref));
}

int	ft_count_move(t_list *pile, t_list *ref, int value, int abs)
{
	int	up;
	int	down;

	up = 0;
	down = 0;
	while (pile && !ft_compare_section(ref, pile->content, value))
	{
		up++;
		pile = pile->next;
	}
	while (pile && ft_compare_section(ref, pile->content, value))
	{
		down++;
		pile = pile->next;
	}
	down = (up + down) - ft_get_list_len(pile);
	if (up < (-down))
		return (up);
	if (abs)
		return (-down);
	return (down);
}

int	ft_compare_moves(t_pile *pile, t_list *ref, t_list *up, t_list *down)
{
	int	r_value;
	int	m_f;
	int	m_s;
	int	m_l;

	r_value = -1;
	m_f = 1;
	m_s = 2;
	m_l = 2;
	if (up)
	{
		m_f += ft_count_move(*pile->b, ref, pile->ia->first, 1);
		r_value = pile->ia->first;
		if (up->next)
			m_s += ft_count_move(*pile->b, ref, pile->ia->second, 1);
		if (m_f > m_s)
			r_value = pile->ia->second;
	}
	if (down)
	{
		m_l += ft_count_move(*pile->b, ref, pile->ia->last, 1);
		if (r_value == -1 || r_value > m_l)
			r_value = pile->ia->last;
	}
	return (r_value);
}

void	ft_do(t_pile *pile, t_list *ref)
{
	int		move;
	char	*action;

	action = "rb";
	move = ft_count_move(*pile->b, ref, pile->ia->first, 1);
	if (move < 0)
	{
		move = -move;
		action = "rrb";
	}
	while (move)
	{
		exec(pile, action);
		move--;
	}
}

int	ft_calcul_move(t_pile *pile, t_list *ref, t_list *up, t_list *down)
{

	int value;
	int moves;

	value = ft_compare_moves(pile, ref, up, down);
	// if (value != -1)
	// {
	// 	exec(pile, "ra");
	// 	return (0);
	// }
	if (value == pile->ia->second)
		exec(pile, "sa");
	if (value == pile->ia->last)
		exec(pile, "rra");
	ft_do(pile, ref);
	exec(pile, "pb");
	// moves = ft_count_move(pile->b, ref, value, 1);
	return (0);
}

void	ft_action_to_b(t_pile *pile, t_list *ref)
{
	t_list	*up;
	t_list	*down;

	up = NULL;
	down = NULL;
	ft_get_extra(*pile->a, ref, &up, &down);
	ft_calcul_move(pile, ref, up, down);
}
