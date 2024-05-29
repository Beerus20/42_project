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

int	ft_select_moveless_value(t_pile *pile, t_list *sub_pile, int (*fa)(t_list*, int), int (*fb)(t_list*, int))
{
	int	r_value;
	int	position_a;
	int	position_b;
	int	total;
	int	tmp;

	position_a = fa(*pile->a, sub_pile->content);
	position_b = fb(*pile->b, sub_pile->content);
	tmp = ft_nb_move(*pile->a, position_a) + ft_nb_move(*pile->b, position_b);
	r_value = sub_pile->content;
	while (sub_pile)
	{
		position_a = fa(*pile->a, sub_pile->content);
		position_b = fb(*pile->b, sub_pile->content);
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
	if (*p_a < 0 && *p_b < 0)
	{
		r_value = *p_b;
		if (*p_a > *p_b)
			r_value = *p_a;
	}
	*p_b -= r_value;
	*p_a -= r_value;
	return (r_value);
}

void	ft_move_to_b(t_pile *pile, t_pile *ref)
{
	t_list	*sub_pile;
	int		position_a;
	int		position_b;
	int		extra_move;
	int		value;
	int		i;

	i = 0;
	sub_pile = ft_get_extra(*pile->a, *ref->a);
	while (sub_pile)
	{
		if (*pile->b)
		{
			value = ft_select_moveless_value(pile, sub_pile, ft_get_index, ft_get_position);
			position_a = ft_position(*pile->a, ft_get_index(*pile->a, value));
			position_b = ft_position(*pile->b, ft_get_position(*pile->b, value));
			extra_move = ft_extra_moves(pile, &position_a, &position_b);
			if (position_a >= 0)
			{
				loop_exec(pile, extra_move, "rr");
				loop_exec(pile, position_a, "ra");
			}
			else
			{
				loop_exec(pile, -extra_move + 1, "rrr");
				loop_exec(pile, -position_a + 1, "rra");
			}
			if (position_b >= 0)
				loop_exec(pile, position_b, "rb");
			else
				loop_exec(pile, -position_b, "rrb");
			ft_del_list_value(&sub_pile, value);
		}
		else
			ft_del_list_value(&sub_pile, sub_pile->content);
		exec(pile, "pb");
	}
}

void	ft_move_to_a(t_pile *pile)
{
	t_list	*sub_pile;
	int		position_a;
	int		position_b;
	int		extra_move;
	int		value;

	sub_pile = *pile->b;
	while (sub_pile)
	{
		value = ft_select_moveless_value(pile, sub_pile, ft_get_position_inv, ft_get_index);
		position_a = ft_get_position_inv(*pile->a, value);
		position_b = ft_get_index(*pile->b, value);
		if (position_a <= pile->ia->len / 2)
		{
			if (position_b <= pile->ib->len / 2)
			{
				while (position_a && position_b)
				{
					exec(pile, "rr");
					position_a--;
					position_b--;
				}
			}
			loop_exec(pile, position_a, "ra");
		}
		else
		{
			if (position_b > pile->ib->len / 2)
			{
				while ((pile->ia->len - position_a) && (pile->ib->len - position_b))
				{
					exec(pile, "rrr");
					position_a++;
					position_b++;
				}
			}
			loop_exec(pile, pile->ia->len - position_a, "rra");
		}
		if (position_b <= pile->ib->len / 2)
			loop_exec(pile, position_b, "rb");
		else
			loop_exec(pile, pile->ib->len - position_b, "rrb");
		exec(pile, "pa");
		sub_pile = *pile->b;
	}
}

int	ft_action(t_pile *pile, t_pile *ref)
{
	t_list	*tmp;
	int		stop;
	int		i;

	i = 0;
	stop = ft_get_list_len(*ref->a) ;
	while (i++ < 100)
	{
		if (ft_search(*ref->a, pile->ia->first) == -1)
			ft_move_to_b(pile, ref);
		else
			exec(pile, "ra");
	}
	// ft_move_to_a(pile);
	// while (pile->ia->first != 0)
	// 	exec(pile, "rra");
	/*
	while (pile->ia->last != stop - 1)
	{
		if (pile->ia->last <= pile->ia->len / 2)
			exec(pile, "rra");
		else
			exec(pile, "ra");
	}*/
	return (0);
}

// rrr : position not yet correct