#include "push_swap.h"

int	ft_action(t_pile *pile, int id_pile, int id_info, int index)
{
	int		position;
	int		value;
	t_list	*tmp;
	t_info	*tmp_info;

	tmp = *(pile->a);
	tmp_info = pile->ia;
	if (id_pile)
		tmp = *(pile->b);
	if (id_info)
		tmp_info = pile->ib;
	value = ft_info(*tmp_info, index);
	position = ft_get_position(tmp, value);
	if ((index == 1 && position == 0 && value < tmp->content)
		|| (index == 0 && position == 1))
	{
		exec(pile, "sa");
		return (1);
	}
	if (index == 2 && position == 1)
	{
		exec(pile, "rra sa");
		return (1);
	}
	if (index == 2 && position > 1)
	{
		exec(pile, "rra");
		return (1);
	}
	return (0);
}

int	ft_to_do(t_pile *pile)
{

	return (0);
}