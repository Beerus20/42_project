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

int	*ft_get_classements(t_list *s_pile, t_list *ref)
{
	int	*tab;
	int	len;
	int	i;

	i = 0;
	len = ft_get_list_len(ref);
	tab = (int *)malloc(sizeof(int) * (len + 1));
	if (!tab)
		exit(1);
	while (i < len + 1)
		tab[i++] = 0;
	while (s_pile)
	{
		if (!ft_search(ref, s_pile->content))
			tab[ft_check_classement(ref, s_pile->content)]++;
		s_pile = s_pile->next;
	}
	// ft_show_tab(tab, len + 1);
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
}t_list	*ft_get_sub_list_sup(t_list *pile, int begin, int end, int value);

int	ft_action(t_pile *pile, t_list *ref)
{
	t_list	*tmp;

	while (!ft_isclean(*pile->a, ref))
	{
		if (!ft_search(ref, (*pile->a)->content))
		{
			ft_move_to_b(pile, ref);
			// exec(pile, "pb");
		}
		else
		{
			exec(pile, "ra");
		}
	}
	return (0);
}
