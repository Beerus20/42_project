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
	return (tab);
}
