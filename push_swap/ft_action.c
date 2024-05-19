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

int	ft_isclean(t_list *pile, t_list *ref, int inv)
{
	while (pile)
	{
		if (!inv && !ft_search(ref, pile->content))
			return (0);
		if (inv && ft_search(ref, pile->content))
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	ft_check_classement(t_list *ref, int value)
{
	int i;

	i = 0;
	while (ref)
	{
		if (value < ref->content)
			return (i);
		i++;
		ref = ref->next;
	}
	return (i);
}

t_list	*ft_get_section(t_list *pile, t_list *ref, int class_id)
{
	t_list	*r_value;

	r_value = NULL;
	while (pile)
	{
		if (ft_check_classement(ref, pile->content) == class_id)
			if (!ft_search(ref, pile->content))
				ft_add_back(&r_value, pile);
		pile = pile->next;
	}
	return (r_value);
}

t_list	**ft_get_classements(t_list *s_pile, t_list *ref)
{
	t_list	**tab;
	int		len;
	int		i;

	i = 0;
	len = ft_get_list_len(ref);
	tab = (t_list **)malloc(sizeof(t_list *) * (len + 1));
	if (!tab)
		exit(1);
	while (i < len + 1)
		tab[i++] = NULL;
	while (s_pile)
	{
		if (!ft_search(ref, s_pile->content))
			ft_add_back(&tab[ft_check_classement(ref, s_pile->content)], s_pile);
		s_pile = s_pile->next;
	}
	// for (size_t j = 0; j < len + 1; j++)
	// {
	// 	ft_printf("case [%d] :\n", j);
	// 	ft_show_pile(tab[j]);
	// }
	return (tab);
}

int	ft_check_ref(t_list *pile, t_list *ref)
{
	while (pile)
	{
		if (ft_search(ref, pile->content))
			return (ft_get_index(ref, pile->content));
		pile = pile->next;
	}
	return (ft_get_list_len(ref) - 1);
}

int	ft_action(t_pile *pile, t_list *ref)
{
	t_list	*tmp;
	int		stop;

	stop = ft_get_last(ref)->content;
	while (!ft_isclean(*pile->a, ref, 0) /* && pile->ia->first != stop */)
	{
		if (!ft_search(ref, (*pile->a)->content))
		{
			// ft_move_to_b(pile, ref);
			exec(pile, "pb");
		}
		else
		{
			// ft_move_to_a(pile, ref);
			exec(pile, "ra");
		}
	}
	return (0);
}
