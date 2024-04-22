#include "./printf/includes/ft_printf.h"
#include "push_swap.h"

void	ft_show(char *title, t_list *pile)
{
	ft_printf("%s	:\n", title);
	while (pile)
	{
		ft_printf("-- %d\n", pile->content);
		pile = pile->next;
	}
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
