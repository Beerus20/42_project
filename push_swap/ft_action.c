#include "push_swap.h"

void	ft_add_ref_value(t_pile *ref, int value)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *ref->a;
	while (tmp && tmp->content < value)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp)
		ft_add_list_value(ref->a, i, value);
	else
		ft_add_back_content(ref->a, value);
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

int	ft_count_move(t_list *pile, t_list *ref, int value)
{
	t_list	*section;
	int		i;
	int		len;
	int		class_id;
	int		position[2];

	if (!pile)
		return (0);
	len = ft_get_list_len(pile);
	class_id = ft_check_classement(ref, value);
	section = ft_get_section(pile, ref, class_id);
	i = class_id;
	while (!section && i--)
		section = ft_get_section(pile, ref, i);
	i = len;
	while (!section && i > class_id)
		section = ft_get_section(pile, ref, i--);
	if (!section)
		return (0);
	position[0] = ft_get_index(pile, section->content);
	position[1] = ft_get_index(pile, ft_get_last(section)->content);
	if (position[0] < (len - position[1]))
		return (position[0]);
	return (position[1] - len);
}

int	ft_get_ref_id(t_list *pile, t_list *ref)
{
	while (ft_search(ref, pile->content) == -1)
		pile = pile->next;
	return (ft_get_index(ref, pile->content));
}

void	ft_pb_action(t_pile *pile, t_pile *ref, int value)
{
	int	position;
	int	move;
	int	tmp_move;

	position = ft_get_index(*pile->a, value);
	move = ft_count_move(*pile->b, *ref->a, value);
	if (position > (pile->ia->len / 2))
		position = position - pile->ia->len;
	if (position >= 0)
	{
		if (move >= 0)
		{
			tmp_move = move;
			if (position <= move)
				tmp_move = position;
			position -= tmp_move;
			move -= tmp_move;
			loop_exec(pile, tmp_move, "rr");
			loop_exec(pile, move, "rb");
			loop_exec(pile, position, "ra");
			exec(pile, "pb");
		}
		else
		{
			loop_exec(pile, move, "rrb");
			loop_exec(pile, position, "ra");
			exec(pile, "pb rrb");
		}
	}
	else
	{
		if (move < 0)
		{
			tmp_move = move;
			if (position >= move)
				tmp_move = position;
			position -= tmp_move + 1;
			move -= tmp_move + 1;
			loop_exec(pile, tmp_move, "rrr");
			loop_exec(pile, move, "rrb");
			loop_exec(pile, -position, "rra");
			exec(pile, "pb rrb");
		}
		else
		{
			loop_exec(pile, move, "rb");
			loop_exec(pile, -position, "rra");
			exec(pile, "pb");
		}
	}
}

void	ft_move_to_b(t_pile *pile, t_pile *ref)
{
	t_list	**classes;
	t_list	*s_pile;
	int		ref_id;
	int		i;

	ref_id = ft_get_ref_id(*pile->a, *ref->a);
	s_pile = ft_get_extra(*pile->a, *ref->a);
	classes = ft_get_classements(s_pile, *ref->a);
	i = ref_id;
	while (i--)
	{
		while (classes[i])
		{
			ft_pb_action(pile, ref, classes[i]->content);
			ft_del_front(&classes[i]);
		}
	}
	i = ft_get_list_len(*ref->a);
	while (i >= ref_id)
	{
		while (classes[i])
		{
			ft_pb_action(pile, ref, classes[i]->content);
			ft_del_front(&classes[i]);
		}
		i--;
	}
}

void	ft_move_to_a(t_pile *pile, t_pile *ref)
{
	t_list	*section;
	t_list	*tmp;
	int		ref_id;
	int		max;
	int		position;
	int		count;

	count = 0;
	tmp = *pile->a;
	ref_id = ft_get_ref_id(*pile->a, *ref->a);
	section = ft_get_section(*pile->b, *ref->a, ref_id);
	while (section)
	{
		max = ft_get_max_value(section);
		position = ft_get_index(*pile->b, max);
		while (pile->ib->first != max)
		{
			if (position <= (pile->ib->len / 2))
				exec(pile, "rb");
			else
				exec(pile, "rrb");
		}
		exec(pile, "pa");
		count++;
		// ft_add_list_value(ref->a, ref_id, max);
		ft_add_ref_value(ref, max);
		ft_del_list_value(&section, max);
	}
	count++;
	while (count)
	{
		exec(pile, "ra");
		count--;
	}
	section = ft_get_section(*pile->b, *ref->a, ref_id + 1);
	while (section)
	{
		max = ft_get_max_value(section);
		position = ft_get_index(*pile->b, max);
		while (pile->ib->first != max)
		{
			if (position <= (pile->ib->len / 2))
				exec(pile, "rb");
			else
				exec(pile, "rrb");
		}
		exec(pile, "pa");
		count++;
		// ft_add_list_value(ref->a, ref_id, max);
		ft_add_ref_value(ref, max);
		ft_del_list_value(&section, max);
	}
	while (count)
	{
		exec(pile, "ra");
		count--;
	}
}

int	ft_action(t_pile *pile, t_pile *ref)
{
	t_list	*tmp;
	int		stop;
	int		i;

	i = 0;
	stop = pile->ia->len;
	while (stop != ft_get_list_len(*ref->a))
	{
			// ft_move_to_b(pile, ref);
			// ft_move_to_a(pile, ref);
			// ft_action_to_b(pile, ref);
			// exec(pile, "pb");
		if (ft_search(*ref->a, pile->ia->first) == -1)
			ft_move_to_b(pile, ref);
		else
			ft_move_to_a(pile, ref);
			// exec(pile, "ra");
			// ft_action_to_a(pile, ref);
	}
	while (pile->ia->last != stop - 1)
	{
		if (pile->ia->last <= pile->ia->len / 2)
			exec(pile, "rra");
		else
			exec(pile, "ra");
	}
	return (0);
}
