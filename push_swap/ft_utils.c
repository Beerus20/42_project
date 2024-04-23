#include "./printf/includes/ft_printf.h"
#include "push_swap.h"

void	ft_show(char *title, t_list *pile_a, t_list *pile_b)
{
	ft_printf("%s	:\n", title);
	while (pile_a || pile_b)
	{
		if (pile_a)
		{
			ft_printf(" %d", pile_a->content);
			pile_a = pile_a->next;
		}
		if (pile_b)
		{
			ft_printf("	%d", pile_b->content);
			pile_b = pile_b->next;
		}
		ft_printf("\n");
	}
	ft_printf(" _	_\n");
	ft_printf(" A	B\n\n");
}

void	ft_show_ipile(t_ipile pile)
{
	ft_printf("PILE INFO : \n");
	if (pile.first)
		ft_printf("- FIRST		: [%d]\n", *(pile.first));
	if (pile.second)
		ft_printf("- SECOND	: [%d]\n", *(pile.second));
	if (pile.last)
		ft_printf("- LAST		: [%d]\n", *(pile.last));
	ft_printf("- LEN		: [%d]\n", pile.len);
}

void	ft_free(t_list **pile)
{
	t_list	*tmp;

	tmp = NULL;
	while (*pile)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		free(tmp);
	}
	free(pile);
}

int	ft_getlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	len;
	int	mul;

	i = 0;
	nb = 0;
	len = ft_getlen(str);
	mul = 1;
	if (len >= 2 && str[0] == '-')
	{
		mul = -1;
		i = 1;
	}
	while (i < len)
	{
		nb = (str[i] - 48) + (nb * 10);
		i++;
	}
	return (nb * mul);
}

void	 ft_init_pile(int argc, char **argv, t_list **pile)
{
	int		i;
	t_list	*tmp;

	i = 1;
	*pile = (t_list *)malloc(sizeof(t_list));
	if (!(*pile))
		return ;
	if (argc < 2)
		return ;
	tmp = (*pile);
	while (i < argc)
	{
		tmp->content = ft_atoi(argv[i]);
		if ((i + 1) < argc)
		{
			tmp->next = (t_list *)malloc(sizeof(t_list));
			if (!tmp)
				return ;
		}
		else
			tmp->next = NULL;
		tmp = tmp->next;
		i++;
	}
}


int	ft_check(t_list *pile, int	argc)
{
	int	to_compare;
	int	i;

	i = 1;
	to_compare = pile->content;
	if (pile->next)
	{
		pile = pile->next;
		i++;
		while (pile)
		{
			if (to_compare > pile->content)
				return (0);
			to_compare = pile->content;
			pile = pile->next;
			i++;
		}
	}
	if (i == argc)
		return (1);
	return (0);
}

t_list	*ft_get_last(t_list *pile)
{
	while (pile->next)
		pile = pile->next;
	return (pile);
}