#include "push_swap.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (value * (-1));
	return (value);
}

int	ft_search(t_list *pile, int value)
{
	int	i;

	i = 0;
	while (pile)
	{
		if (pile->content == value)
			return (i);
		i++;
		pile = pile->next;
	}
	return (-1);
}

int	ft_position(t_list *pile, int position)
{
	int	len;

	len = ft_get_list_len(pile);
	if (position <= len / 2)
		return (position);
	return (position - len);
}

int	ft_nb_move(t_list *pile, int position)
{
	return (ft_abs(ft_position(pile, position)));
}

int	ft_get_position(t_list *pile, int value)
{
	t_list	*tmp;
	int		max;
	int		min;

	max = ft_get_max_value(pile);
	if (max < value)
		return (ft_get_index(pile, max));
	min = ft_get_min_value(pile);
	if (min > value)
		return (ft_get_index(pile, min) + 1);
	tmp = ft_move_to(pile, max);
	while (tmp && tmp->content > value)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = pile;
		while (tmp->content != max && tmp->content > value)
			tmp = tmp->next;
	}
	return (ft_get_index(pile, tmp->content));
}

int	ft_get_position_inv(t_list *pile, int value)
{
	t_list	*tmp;
	t_list	*list;
	int		index;

	tmp = pile;
	list = NULL;
	while (tmp)
	{
		if (tmp->content > value)
			ft_add_back_content(&list, tmp->content);
		tmp = tmp->next;
	}
	if (!list)
		return (ft_get_index(pile, ft_get_max_value(pile)) + 1);
	return (ft_get_index(pile, ft_get_min_value(list)));
}

int	ft_select_moveless_value(t_pile *pile, t_list *sub_pile, t_action action)
{
	int	r_value;
	int	position_a;
	int	position_b;
	int	total;
	int	tmp;

	position_a = action.fa(*pile->a, sub_pile->content);
	position_b = action.fb(*pile->b, sub_pile->content);
	tmp = ft_nb_move(*pile->a, position_a) + ft_nb_move(*pile->b, position_b);
	r_value = sub_pile->content;
	while (sub_pile)
	{
		position_a = action.fa(*pile->a, sub_pile->content);
		position_b = action.fb(*pile->b, sub_pile->content);
		total = ft_nb_move(*pile->a, position_a) + ft_nb_move(*pile->b, position_b);
		if (total < tmp)
		{
			r_value = sub_pile->content;
			tmp = total;
		}
		sub_pile = sub_pile->next;
	}
	return (r_value);
}

int	ft_extra_moves(t_pile *pile, int *p_a, int *p_b)
{
	int	r_value;

	r_value = 0;
	if (*p_a >= 0 && *p_b >= 0)
	{
		r_value = *p_a;
		if (*p_a > *p_b)
			r_value = *p_b;
	}
	else if (*p_a < 0 && *p_b < 0)
	{
		r_value = *p_b + 1;
		if (*p_a > *p_b)
			r_value = *p_a + 1;
	}
	*p_b -= r_value;
	*p_a -= r_value;
	return (r_value);
}

void	ft_move(t_pile *pile, int p_a, int p_b)
{
	int	extra_move;

	extra_move = ft_extra_moves(pile, &p_a, &p_b);
	if (p_a >= 0)
	{
		loop_exec(pile, extra_move, "rr");
		loop_exec(pile, p_a, "ra");
	}
	else
	{
		loop_exec(pile, -extra_move, "rrr");
		loop_exec(pile, -p_a, "rra");
	}
	if (p_b >= 0)
		loop_exec(pile, p_b, "rb");
	else
	{
		if (*pile->b)
			loop_exec(pile, -p_b, "rrb");
	}
}

void	ft_move_element(t_pile *pile, t_list *sub_pile, t_action action)
{
	int		position_a;
	int		position_b;
	int		value;

	while (sub_pile)
	{
		value = ft_select_moveless_value(pile, sub_pile, action);
		position_a = ft_position(*pile->a, action.fa(*pile->a, value));
		position_b = ft_position(*pile->b, action.fb(*pile->b, value));
		ft_move(pile, position_a, position_b);
		ft_del_list_value(&sub_pile, value);
		exec(pile, action.end_action);
	}
}

int	ft_action(t_pile *pile, t_pile *ref)
{
	t_list		*tmp;
	t_action	action_1;
	t_action	action_2;
	int			stop;
	int			i;

	i = 0;

	action_1.end_action = "pb";
	action_1.fa = ft_get_index;
	action_1.fb = ft_get_position;

	stop = pile->ia->len - (pile->ia->len / 3) ;
	while (pile->ia->len >= stop)
	{
		tmp = ft_get_extra(*pile->a, *ref->a);
		if (ft_search(*ref->a, pile->ia->first) == -1)
			ft_move_element(pile, tmp, action_1);
		else
			exec(pile, "ra");
	}
	tmp = NULL;
	while (pile->ia->first != (*ref->a)->content)
	{
		if (ft_search(*ref->a, pile->ia->first) == -1)
		{
			ft_add_back_content(&tmp, pile->ia->first);
			exec(pile, "pb");
		}
		else
			exec(pile, "ra");
	}
	action_2.end_action = "pa";
	action_2.fa = ft_get_position_inv;
	action_2.fb = ft_get_index;
	ft_move_element(pile, tmp, action_2);
	ft_move_element(pile, ft_copy_list(*pile->b), action_2);
	stop = ft_position(*pile->a, ft_get_index(*pile->a, ft_get_max_value(*pile->a)));
	request_loop(pile, stop >= 0, stop + 1, "ra");
	request_loop(pile, stop < 0, stop, "rra");
	return (0);
}
