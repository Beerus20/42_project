#include "../push_swap.h"

t_cmd	*ft_init_cmd(char *value)
{
	t_cmd	*r_cmd;

	r_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!r_cmd)
		exit(1);
	r_cmd->content = value;
	r_cmd->next = NULL;
	return (r_cmd);
}

void	ft_add_cmd(t_cmd **cmds, char *value)
{
	t_cmd	*tmp_list;
	t_cmd	*tmp;

	tmp = ft_init_cmd(NULL);
	tmp_list = *cmds;
	if (tmp_list)
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp->content = value;
		tmp_list->next = tmp;
	}
	else
	{
		tmp->content = value;
		*cmds = tmp;
	}
}

t_cmd	*ft_get_cmd()
{
	char	*cmd;
	t_cmd	*cmds;

	cmds = NULL;
	cmd = get_next_line(1);
	while (cmd)
	{
		ft_add_cmd(&cmds, cmd);
		free(cmd);
		cmd = get_next_line(1);
	}
	return (cmds);
}

int main(int argc, char const *argv[])
{
	t_pile	*pile;

	pile = ft_init();
	if (ft_init_pile(argc, argv, pile->a))
	{
		ft_get_info(pile->a, pile->ia);
		ft_get_info(pile->b, pile->ib);
	}
	ft_free_pile(pile);
	return 0;
}
