#include "push_swap.h"

t_list	*ft_get_portion(t_list *pile, t_list *ref)
{
	t_list	*r_value;

	r_value = NULL;
	while (pile && ft_search(ref, pile->content) == -1)
	{
		ft_add_back_content(&r_value, pile->content);
		pile = pile->next;
	}
	return (r_value);
}

t_list	*ft_sub_list(t_list *list, int begin, int end)
{
	t_list	*r_value;
	int		subst;

	r_value = NULL;
	if (ft_get_index(list, end) < ft_get_index(list, begin))
	{
		subst = end;
		end = begin;
		begin = subst;
	}
	list = ft_move_to(list, begin);
	while (list && list->content != end)
	{
		ft_add_back_content(&r_value, list->content);
		list = list->next;
	}
	if (list && list->content == end)
		ft_add_back_content(&r_value, list->content);
	return (r_value);
}

t_list	*ft_sub_list_between(t_list *list, int a, int b)
{
	t_list	*r_value;
	int		tmp;

	r_value = NULL;
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (list)
	{
		if (list->content >= a && list->content <= b)
			ft_add_back_content(&r_value, list->content);
		list = list->next;
	}
	return (r_value);
}

void	ft_show_tab(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("tab[%d]	: [%d]\n", i, tab[i]);
		i++;
	}
}

void	ft_show(t_pile pile)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *(pile.a);
	tmp_b = *(pile.b);
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf(" %d", tmp_a->content);
			tmp_a = tmp_a->next;
		}
		if (tmp_b)
		{
			ft_printf(" 	%d", tmp_b->content);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf(" _	_\n");
	ft_printf(" A	B\n\n");
}

void	ft_show_info(t_pile pile)
{
	ft_printf("\033[0;33mPILE INFO : \033[0;0m\n");
	if ((pile.ia)->first)
		ft_printf("\033[0;0m- FIRST		: \033[0;31m[%d] ", pile.ia->first);
	if ((pile.ib)->first)
		ft_printf(" [%d]\033[0;0m", pile.ib->first);
	ft_printf("\n");
	if ((pile.ia)->second)
		ft_printf("\033[0;0m- SECOND	: \033[0;31m[%d] ", pile.ia->second);
	if ((pile.ib)->second)
		ft_printf(" [%d]\033[0;0m", pile.ib->second);
	ft_printf("\n");
	if ((pile.ia)->last)
		ft_printf("\033[0;0m- LAST		: \033[0;31m[%d] ", pile.ia->last);
	if ((pile.ib)->last)
		ft_printf(" [%d]\033[0;0m", pile.ib->last);
	ft_printf("\033[0;0m\n");
	ft_printf("- LEN		: \033[0;31m[%d]  [%d]\033[0;0m\n", pile.ia->len, pile.ib->len);
	ft_printf("		  \033[0;32m[A]  [B]\033[0;0m\n");
}

void	ft_show_pile(t_list *pile)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp)
	{
		ft_printf(" [%d]\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("  _\n");
	ft_printf("  A\n\n");
}

void	ft_show_diff(t_list *pile, t_list *tmp_pile)
{
	while (pile)
	{
		if (tmp_pile && ft_search(tmp_pile, pile->content) != -1)
			ft_printf(" \033[0;31m[%d]\033[0;0m\n", pile->content);
		else
			ft_printf(" [%d]\n", pile->content);
		pile = pile->next;
	}
	ft_printf("  _\n");
	ft_printf("  A\n\n");
}

void	ft_show_test(t_list *pile, int *tab)
{
	int	i;

	i = 0;
	while (pile)
	{
		ft_printf(" [%d]	[%d]\n", pile->content, tab[i]);
		pile = pile->next;
		i++;
	}
	ft_printf("  _	 _\n");
	ft_printf("  A	 T\n\n");
}

int	request(t_pile *pile, int question, char *to_do)
{
	if (question)
	{
		exec(pile, to_do);
		return (1);
	}
	return (0);
}

int	request_loop(t_pile *pile, int question, int nb_iter ,char *to_do)
{
	if (question)
	{
		loop_exec(pile, nb_iter, to_do);
		return (1);
	}
	return (0);
}