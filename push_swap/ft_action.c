#include "push_swap.h"

int	ft_search(t_list *pile, int value)
{
	// if (ft_check_issmaller(pile, value))
	// 	return (1);
	while (pile)
	{
		if (pile->content == value)
			return (1);
		pile = pile->next;
	}
	return (0);
}

int	ft_position_of(t_list *pile, int value)
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

int	ft_get_position(t_list *pile, int value, int behind)
{
	if (pile == NULL)
		return (0);
	if (behind)
	{
		if (value >= ft_get_max_value(pile))
			value = ft_get_min_value(pile);
		else
			value++;
	}
	else
	{
		if (value <= ft_get_min_value(pile))
			value = ft_get_max_value(pile);
		else
			value--;
	}
	while (!ft_search(pile, value))
	{
		if (behind)
			value++;
		else
			value--;
	}
	return (ft_position_of(pile, value));
}

int	ft_arrange(t_pile *pile)
{
	int		i;
	int		first_nb;
	int 	second_nb;
	int 	question;
	t_list	*tmp;

	i = 0;
	tmp = *pile->a;
	first_nb = ft_check_increas(tmp);
	second_nb = 0;
	while (i++ < first_nb)
	{
		if (tmp->next && ft_get_position(*pile->a, tmp->content, 1) != ft_position_of(*pile->a, tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	second_nb = ft_check_increas(tmp);
	question = *pile->b == NULL && (first_nb + second_nb) == pile->ia->len;
	if (question)
	{
		request_loop(pile, first_nb <= second_nb, first_nb , "ra");
		request_loop(pile, first_nb > second_nb, second_nb , "rra");
		return (1);
	}
	return (0);
}

int	ft_isclean(t_list *pile, t_list *ref)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp)
	{
		if (!ft_search(ref, tmp->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_action(t_pile *pile, t_list *ref)
{
	while (!ft_isclean(*pile->a, ref))
	{
		if (!ft_search(ref, (*pile->a)->content))
		{
			// while (pile->ia->first > ft_get_last(ref)->content)
			// {
			// 	ft_add_back(&ref, ft_init_list(pile->ia->first));
			// 	exec(pile, "ra");
			// 	ft_show_pile(ref);
			// }
			exec(pile, "pb");
		}
		else
			exec(pile, "ra");
	}
	return (0);
}
