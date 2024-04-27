#include "push_swap.h"

void	ft_action(t_pile *pile, int id_pile, int id_info, int index)
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
	if (index == 1 && position == 0 && value < tmp->content)
		exec(pile, "sa");
	
}
