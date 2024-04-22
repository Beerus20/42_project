#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	ft_sa(t_list **pile);
#endif