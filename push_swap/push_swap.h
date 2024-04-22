#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	ft_swap(t_list **pile);
void	ft_push(t_list **pile_a, t_list **pile_b);
void	ft_rotate(t_list **pile);
void	ft_rev_rotate(t_list **pile);

/**	_________________ UTILS _________________ **/
void	ft_show(char *title, t_list *pile);
void	ft_free(t_list **pile);
int		ft_getlen(char *str);
int		ft_atoi(char *str);
void	ft_init_pile(int argc, char **argv, t_list **pile);

#endif