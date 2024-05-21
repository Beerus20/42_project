#include "push_swap.h"

<<<<<<< HEAD
void	ft_b_action(t_pile *pile, t_list *ref)
{
	t_list	*tmp_b;
	int		value_class;
	int		i;
	int		position;

	position = -1;
	tmp_b = *pile->b;
	value_class = ft_check_classement(ref, pile->ia->first);
	while (tmp_b)
	{
		if (ft_check_classement(ref, tmp_b->content) == value_class)
		{
			while (pile->ib->first != tmp_b->content)
				exec(pile, "ra");
			break ;
		}
		tmp_b = tmp_b->next;
	}
	exec(pile, "pb");
}

void	ft_apply_(t_pile *pile, t_list *ref, t_list *s_ref)
{
	int	position;
	int	len;

	position = 0;
	len = 0;
	while (s_ref && !ft_isclean(*pile->a, s_ref, 1))
	{
		len = ft_get_list_len(*pile->a);
		position = ft_get_index(*pile->a, s_ref->content);
		// while (pile->ia->first != s_ref->content)
		// {
		// 	request(pile, position <= len / 2, "ra");
		// 	request(pile, position > len / 2, "rra");
		// }
		s_ref = s_ref->next;
		ft_b_action(pile, ref);
		exec(pile, "pb");
	}
}

int	ft_get_ref_val_last(t_list *pile, t_list *ref)
{
	int	r_value;

	r_value = -1;
	while (pile)
	{
		if (ft_search(ref, pile->content))
			r_value = pile->content;
		pile = pile->next;
	}
	return (r_value);
}

t_list	*ft_get_sub_ref(t_pile *pile, t_list *ref)
{
	t_list	*r_value;
	t_list	*up;
	t_list	*down;
	int		stop;
	int		class_id;

	class_id = ft_check_ref(*pile->a, ref);
	stop = ft_get_value(ref, class_id);
	up = ft_get_sub_list_sup(*pile->a, pile->ia->first, stop, -1);
	down = ft_get_sub_list_sup(*pile->a, ft_get_ref_val_last(*pile->a, ref), pile->ia->last, -1);
	r_value = up;
	while (up->next)
		up = up->next;
	up->next = down;
	return (r_value);
}

void	ft_move_to_b(t_pile *pile, t_list *ref)
=======
int	ft_check_additional_ref(t_list *pile, t_list *ref)
>>>>>>> debug
{
	t_list	*list;
	t_list	*tmp;
<<<<<<< HEAD
	t_list	**classments;
	int		i;
	int		len_ref;
	int		class_id;

	len_ref = ft_get_list_len(ref) + 1;
	class_id = ft_check_ref(*pile->a, ref);
	i = class_id;
	tmp = ft_get_sub_ref(pile, ref);
	classments = ft_get_classements(tmp, ref);
	while (i--)
		ft_apply_(pile, ref, classments[i]);
	while (len_ref-- > class_id)
		ft_apply_(pile, ref, classments[len_ref]);
}


void	ft_move_to_a(t_pile *pile, t_list *ref)
{
	t_list	*tmp;
	int		position;
=======
	t_list	*add_ref;
	int		last;
>>>>>>> debug
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
