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
		ft_printf("\033[0;0m- FIRST		: \033[0;31m[%d] ", *((pile.ia)->first));
	if ((pile.ib)->first)
		ft_printf(" [%d]\033[0;0m", *((pile.ib)->first));
	ft_printf("\n");
	if ((pile.ia)->second)
		ft_printf("\033[0;0m- SECOND	: \033[0;31m[%d] ", *((pile.ia)->second));
	if ((pile.ib)->second)
		ft_printf(" [%d]\033[0;0m", *((pile.ib)->second));
	ft_printf("\n");
	if ((pile.ia)->last)
		ft_printf("\033[0;0m- LAST		: \033[0;31m[%d] ", *((pile.ia)->last));
	if ((pile.ib)->last)
		ft_printf(" [%d]\033[0;0m", *((pile.ib)->last));
	ft_printf("\033[0;0m\n");
	ft_printf("- LEN		: \033[0;31m[%d]  [%d]\033[0;0m\n", *((pile.ia)->len), *((pile.ib)->len));
	ft_printf("		  \033[0;32m[A]  [B]\033[0;0m\n");
}
