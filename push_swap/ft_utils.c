#include "push_swap.h"

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
		if (tmp_pile && pile->content == tmp_pile->content)
		{
			ft_printf(" \033[0;31m[%d]\033[0;0m\n", pile->content);
			tmp_pile = tmp_pile->next;
		}
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