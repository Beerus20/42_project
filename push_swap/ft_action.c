#include "push_swap.h"

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

int	ft_get_last_ref_id(t_list *pile, t_list *ref)
{
	t_list	*tmp;

	tmp = NULL;
	while (pile)
	{
		if (ft_search(ref, pile->content) != -1)
			tmp = pile;
		pile = pile->next;
	}
	return (ft_get_index(ref, tmp->content));
}

void	ft_calcul_move(int *position, int *move, int *sup)
{
	if (*position >= 0 && move >= 0)
	{
		*sup = *move;
		if (*position <= *move)
			*sup = *position;
		*position -= *sup;
		*move -= *sup;
	}
	if (*position < 0 && *move < 0)
	{
		*sup = *move;
		if (*position >= *move)
			*sup = *position;
		*position -= *sup + 1;
		*move -= *sup + 1;
	}
}

void	ft_moves(t_pile *pile, int position, int move, int sup)
{
	if (position >= 0 && move >= 0)
	{
		ft_calcul_move(&position, &move, &sup);
		loop_exec(pile, sup, "rr");
		loop_exec(pile, move, "rb");
		loop_exec(pile, position, "ra");
	}
	else if (position >= 0 && move < 0)
	{
		loop_exec(pile, move, "rrb");
		loop_exec(pile, position, "ra");
	}
	else if (position < 0 && move < 0)
	{
		ft_calcul_move(&position, &move, &sup);
		loop_exec(pile, sup, "rrr");
		loop_exec(pile, move, "rrb");
		loop_exec(pile, -position, "rra");
	}
	else
	{
		loop_exec(pile, move, "rb");
		loop_exec(pile, -position, "rra");
	}
}

void	ft_pb_action(t_pile *pile, t_pile *ref, int value)
{
	int	position;
	int	move;
	int	tmp_move;

	tmp_move = 0;
	position = ft_get_index(*pile->a, value);
	move = ft_count_move(*pile->b, *ref->a, value);
	if (position > (pile->ia->len / 2))
		position = position - pile->ia->len;
	ft_moves(pile, position, move, tmp_move);
	exec(pile, "pb");
}

void	ft_move_a_section_values(t_pile *pile, t_pile *ref, t_list **list)
{
	while (*list)
	{
		ft_pb_action(pile, ref, (*list)->content);
		ft_del_front(list);
	}
}

int	ft_move_b_section_values(t_pile *pile, t_pile *ref, t_list **list, int ref_id)
{
	int		moves;
	int		max;
	int 	position;

	moves = 0;
	while (*list)
	{
		max = ft_get_max_value(*list);
		position = ft_get_index(*pile->b, max);
		while (pile->ib->first != max)
		{
			if (position <= (pile->ib->len / 2))
				exec(pile, "rb");
			else
				exec(pile, "rrb");
		}
		exec(pile, "pa");
		moves++;
		ft_add_list_value(ref->a, ref_id, max);
		ft_del_list_value(list, max);
	}
	return (moves);
}

void	ft_move_to_a(t_pile *pile, t_pile *ref)
{
	t_list	*section;
	int		ref_id;
	int		max;
	int		position;
	int		count;

	count = 0;
	ref_id = ft_get_ref_id(*pile->a, *ref->a);
	section = ft_get_section(*pile->b, *ref->a, ref_id);
	count = ft_move_b_section_values(pile, ref, &section, ref_id);
	count++;
	while (count)
	{
		exec(pile, "ra");
		count--;
	}
	section = ft_get_section(*pile->b, *ref->a, ref_id + 1);
	count = ft_move_b_section_values(pile, ref, &section, ref_id + 1);
	while (count)
	{
		exec(pile, "ra");
		count--;
	}
}

void	ft_move_to_b(t_pile *pile, t_pile *ref)
{
	t_list	**classes;
	t_list	*s_pile;
	int		ref_id;
	int		i;
	int		index;

	ref_id = ft_get_ref_id(*pile->a, *ref->a);
	s_pile = ft_get_extra(*pile->a, *ref->a);
	classes = ft_get_classements(s_pile, *ref->a);
	i = ref_id;
	while (i--)
		ft_move_a_section_values(pile, ref, &classes[i]);
	i = ft_get_list_len(*ref->a);
	while (i >= ref_id)
	{
		ft_move_a_section_values(pile, ref, &classes[i]);
		i--;
	}
	classes = ft_get_classements(*pile->b, *ref->a);
	while (ft_search(*ref->a, pile->ia->last))
	{
			exec(pile, "rra");
			index = ft_get_index(*ref->a, pile->ia->first);
			ft_move_b_section_values(pile, ref, &classes[index], index);
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
		if (ft_search(*ref->a, pile->ia->first) == -1)
			ft_move_to_b(pile, ref);
		else
			ft_move_to_a(pile, ref);
		// while (*pile->b)
		// {
		// 	ft_move_to_a(pile, ref);
		// }
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
