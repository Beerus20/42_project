#include "push_swap.h"

void	ft_show(t_pile pile)
{
	while (*(pile.a) || *(pile.b))
	{
		if (*(pile.a))
		{
			ft_printf(" %d", (*(pile.a))->content);
			*(pile.a) = (*(pile.a))->next;
		}
		if (*(pile.b))
		{
			ft_printf(" %d", (*(pile.b))->content);
			*(pile.a) = (*(pile.b))->next;
		}
		ft_printf("\n");
	}
	ft_printf(" _	_\n");
	ft_printf(" A	B\n\n");
}

void	ft_show_ipile(t_pile pile)
{
	ft_printf("PILE INFO : \n");
	if ((pile.ia)->first)
		ft_printf("- FIRST		: [%d] ", (pile.ia)->first);
	if ((pile.ib)->first)
		ft_printf(" [%d]", (pile.ib)->first);
	ft_printf("\n");
	if ((pile.ia)->second)
		ft_printf("- SECOND	: [%d] ", (pile.ia)->second);
	if ((pile.ib)->second)
		ft_printf(" [%d]", (pile.ib)->second);
	ft_printf("\n");
	if ((pile.ia)->last)
		ft_printf("- LAST		: [%d] ", (pile.ia)->last);
	if ((pile.ib)->last)
		ft_printf(" [%d]", (pile.ib)->last);
	ft_printf("\n");
	ft_printf("- LEN		: [%d]  [%d]\n", (pile.ia)->len, (pile.ib)->len);
	ft_printf("		  [A]  [B]\n\n");
}
