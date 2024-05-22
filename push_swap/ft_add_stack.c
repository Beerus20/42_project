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

int	ft_upper_section(t_list **classes, t_list *ref)
{
	int		r_value;
	int		i;
	int		len;
	int		to_compare;
	int		upper_len;

	r_value = 0;
	i = 0;
	to_compare = 0;
	upper_len = 0;
	len = ft_get_list_len(ref) + 1;
	while (i < len)
	{
		to_compare = ft_get_list_len(classes[i]);
		if (upper_len < to_compare)
		{
			upper_len = to_compare;
			r_value = i;
		}
		i++;
	}
	return (r_value);
}

int	ft_nb_move(t_list *pile, t_list *ref, int value, int direction)
{
	int	nb_move_up;
	int	nb_move_down;
	int	section;

	nb_move_up = 0;
	nb_move_down = 0;
	section = ft_check_classement(ref, value);
	if (!ft_has_section(pile, ref, section))
		return (0);
	while (pile && ft_check_classement(ref, pile->content) != section)
	{
		nb_move_up++;
		pile = pile->next;
	}
	while (pile && ft_check_classement(ref, pile->content) == section)
	{
		nb_move_down++;
		pile = pile->next;
	}
	nb_move_down = (nb_move_up + nb_move_down) - ft_get_list_len(ref);
	if (direction)
		return (nb_move_down);
	return (nb_move_up);
}

int	ft_calcul_move(int p_a, int p_b)
{
	if (p_a > 0 && p_b > 0)
	{
		if (p_a > p_b)
			return (p_a - p_b);
		return (p_b - p_a);
	}
	if (p_a < 0 && p_b < 0)
	{
		if (p_a > p_b)
			return (p_a + (-p_b));
		return ((-p_a) + p_b);
	}
	if (p_a < 0)
		return ((-p_a) + p_b);
	if (p_b < 0)
		return (p_a + (-p_b));
	return (0);
}

void	ft_r_action(t_pile *pile, t_list *ref, int value)
{
	int		up;
	int		down;
	int		position;
	int		move;
	int		tmp;

	up = ft_nb_move(*pile->b, ref, value, 0);
	down = ft_nb_move(*pile->b, ref, value, 1);
	position = ft_get_index(*pile->a, value);
	if (ft_calcul_move(up, position) < ft_calcul_move(down, position))
	{
		move = position;
		if (up < position)
			move = up;
		tmp = move;
		while (move-- && up--)
			exec(pile, "rr");
		while (up--)
			exec(pile, "rb");
	}
	else
	{
		tmp = down;
		while (down++ < 0)
			exec(pile, "rrb");
	}
	while (pile->ia->first != value)
		exec(pile, "ra");
	if (tmp < 0)
	{
		tmp--;
		while (tmp++)
			exec(pile, "rb");
	}
	exec(pile, "pb");
}

void	ft_rr_action(t_pile *pile, t_list *ref, int value)
{
	int		up;
	int		down;
	int		position;
	int		move;

	up = ft_nb_move(*pile->b, ref, value, 0);
	down = ft_nb_move(*pile->b, ref, value, 1);
	position = ft_get_index(*pile->a, value);
	if (ft_calcul_move(up, position) > ft_calcul_move(down, position))
	{
		move = position;
		if (down > position)
			move = down;
		while (move++ && down++ < 0)
			exec(pile, "rrr");
		while (down++ < 0)
			exec(pile, "rrb");
	}
	else
	{
		while (up--)
			exec(pile, "rb");
	}
	while (pile->ia->first != value)
		exec(pile, "rra");
	exec(pile, "pb");
}

int	ft_do_move(t_pile *pile, t_list *ref, t_list *up, t_list *down)
{
	t_list	**classes;
	int		index;
	int		len;
	int		position;

	ft_add_back(&up, down);
	classes = ft_get_classements(up, ref);
	len = -1;
	position = -1;
	while (up && len)
	{
		index = ft_upper_section(classes, ref);
		len = ft_get_list_len(classes[index]);
		while (classes[index])
		{
			position = ft_get_index(*pile->a, classes[index]->content);
			if (position <= pile->ia->len / 2)
				ft_r_action(pile, ref, classes[index]->content);
			else
				ft_rr_action(pile, ref, classes[index]->content);

			ft_del_front(&classes[index]);
		}
	}
	// exec(pile, "pb");
	return (0);
}

void	ft_action_to_b(t_pile *pile, t_list *ref)
{
	t_list	*up;
	t_list	*down;

	up = NULL;
	down = NULL;
	ft_get_extra(*pile->a, ref, &up, &down);
	ft_do_move(pile, ref, up, down);
}

void	ft_action_to_a(t_pile *pile, t_list *ref)
{
	t_list	*section;
	// int		up;
	// int		down;
	int		class_id;
	int		max;
	int		position;
	int		len;

	class_id = ft_get_index(ref, pile->ia->first);
	// up = ft_nb_move(*pile->b, ref, pile->ia->first, 0);
	// down = ft_nb_move(*pile->b, ref, pile->ia->first, 1);
	if (ft_has_section(*pile->b, ref, class_id))
	{
		section = ft_get_section(*pile->b, ref, class_id);
		len = ft_get_list_len(section) + 1;
		while (section)
		{
			position = ft_get_index(*pile->b, max);
			max = ft_get_max_value(section);
			if (position <= pile->ib->len / 2)
			{
				while (pile->ib->first != max)
					exec(pile, "rb");
			}
			else
			{
				while (pile->ib->first != max)
					exec(pile, "rrb");
			}
			ft_del_list_value(&section, max);
			exec(pile, "pa");
			ft_add_list_value(&ref, class_id, max);
		}
		while (len)
		{
			exec(pile, "ra");
			len--;
		}
		// ft_show(*pile);
		// exit(0);
	}
	else
	{
	// 	ft_printf("ATO\n");
		exec(pile, "ra");
	}
}