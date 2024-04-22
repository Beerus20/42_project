#include <stdio.h>
#include "./printf/includes/ft_printf.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *l1;
	t_list *l2;
	t_list **tmp;

	l1 = (t_list *)malloc(sizeof(t_list));
	l1->content = 1;
	l2 = (t_list *)malloc(sizeof(t_list));
	l1->next = l2;
	l2->content = 2;
	l2->next = NULL;
	tmp = &l1;
	ft_sa(tmp);
	while (*tmp)
	{
		ft_printf("%d\n", (*tmp)->content);
		*tmp = (*tmp)->next;
	}
	return (0);
}