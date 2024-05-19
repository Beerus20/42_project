#include "push_swap.h"

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
{
	t_list	*tmp;
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
	int		len;
	int		stop;
	int		max;

	stop = pile->ia->first;
	tmp = ft_get_section(*pile->b, ref, ft_get_index(ref, pile->ia->first));
	while (tmp)
	{
		len = ft_get_list_len(*pile->b);
		max = ft_get_max_value(tmp);
		position = ft_get_index(*pile->b, max);
		while (pile->ib->first != max)
		{
			request(pile, position <= len / 2, "rb");
			request(pile, position > len / 2, "rrb");
		}
		exec(pile, "pa");
		ft_del_list_value(&tmp, max);
	}
	while (pile->ia->first != stop)
		exec(pile, "ra");
	exec(pile, "ra");
}
