#include "push_swap.h"

int	ft_add_to_a(t_pile *pile)
{
	int	p_a;

	if (!(*pile->b))
		return (0);
	p_a = ft_get_position(*pile->a, (*(pile->b))->content);
	if (p_a < 2 && (*(pile->b))->content < (*(pile->a))->content)
	{
		exec(pile, "pa");
		return (1);
	}
	return (0);
}

int	ft_add_to_b(t_pile *pile)
{
	int	position;

	position = ft_get_position_inv(*(pile->b), (*(pile->a))->content);
	if (*(pile->b) == NULL)
	{
		exec(pile, "pb");
		return (1);
	}
	if (position > *(pile->ib->len) / 2)
	{
		position = *(pile->ib->len) - position;
		while (position--)
			exec(pile, "rrb");
		exec(pile, "pb");
		return (1);
	}
	else
	{
		while (position--)
			exec(pile, "rb");
		exec(pile, "pb");
		return (1);
	}
	return (0);
}

int	ft_to_do_first(t_pile *pile, t_list *tmp, int position, int value)
{
	t_info	*to_use;
	int		min;
	int		max;

	min = ft_get_min_value(tmp);
	max = ft_get_max_value(tmp);
	to_use = pile->ia;
	if (*(pile->b) == tmp)
		to_use = pile->ib;
	if (tmp->content == max && ft_check_isalign(tmp->next))
	{
		exec(pile, "ra");
		return (1);
	}
	if (position == 1)
	{
		exec(pile, "sa");
		return (1);
	}
	// else if (position != (*to_use->len - 2) && position > 1 && *(to_use->last) > value)
	// {
	// 	ft_add_to_b(pile);
	// 	return (1);
	// }
	return (0);
}

int	ft_to_do_second(t_pile *pile, t_list *tmp, int position, int value)
{
	if (position == 0 && value < tmp->content)
	{
		exec(pile, "sa");
		return (1);
	}
	return (0);
}

int	ft_to_do_last(t_pile *pile, t_list *tmp, int position, int value)
{
	t_info	*to_use;

	to_use = pile->ia;
	if (*(pile->b) == tmp)
		to_use = pile->ib;
	if (position >= 1 || !ft_check_isalign(tmp))
	{
		if (ft_get_position(tmp, tmp->content) != 0 || ft_get_max_value(tmp) == tmp->content)
		{
			ft_add_to_b(pile);
			return (1);
		}
		exec(pile, "rra");
		if (position == 1)
		{
			exec(pile, "sa");
			ft_add_to_a(pile);
		}
		return (1);
	}
	return (0);
}

int	ft_action(t_pile *pile, int id_pile, int id_info, int index)
{
	int		position;
	int		value;
	t_list	*tmp;
	t_info	*tmp_info;

	tmp = *(pile->a);
	tmp_info = pile->ia;
	if (id_pile)
		tmp = *(pile->b);
	if (id_info)
		tmp_info = pile->ib;
	value = ft_info(*tmp_info, index);
	position = ft_get_position(tmp, value);
	// ft_printf("POSITION	: [%d]\nINDEX		: [%d]\nVALUE		: [%d]\n\n", position, index, value);
	if (index == 0)
		return (ft_to_do_first(pile, tmp, position, value));
	if (index == 1)
		return (ft_to_do_second(pile, tmp, position, value));
	if (index == 2)
		return (ft_to_do_last(pile, tmp, position, value));
	return (0);
}
