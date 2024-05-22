#include "push_swap.h"

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

int	ft_has_section(t_list *pile, t_list *ref, int section)
{
	while (pile)
	{
		if (ft_check_classement(ref, pile->content) == section)
			return (1);
		pile = pile->next;
	}
	return (0);
}

int	ft_compare_section(t_list *ref, int a, int b)
{
	return (ft_check_classement(ref, a) == ft_check_classement(ref, b));
}

t_list	*ft_get_section(t_list *pile, t_list *ref, int class_id)
{
	t_list	*r_value;

	r_value = NULL;
	while (pile)
	{
		if (ft_check_classement(ref, pile->content) == class_id)
			if (ft_search(ref, pile->content) == -1)
				ft_add_back_content(&r_value, pile->content);
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
		if (ft_search(ref, s_pile->content) == -1)
			ft_add_back_content(&tab[ft_check_classement(ref, s_pile->content)], s_pile->content);
		s_pile = s_pile->next;
	}
	return (tab);
}
