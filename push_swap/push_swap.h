#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
typedef struct s_ipile
{
	int	*first;
	int	*second;
	int	*last;
	int	len;
}	t_ipile;

void	ft_swap(t_list **pile);
void	ft_push(t_list **pile_a, t_list **pile_b);
void	ft_rotate(t_list **pile);
void	ft_rev_rotate(t_list **pile);

/**	_________________ UTILS _________________ **/
t_list	*ft_get_last(t_list *pile);
int		ft_check(t_list *pile, int	argc);
void	ft_show(char *title, t_list *pile_a, t_list *pile_b);
void	ft_show_ipile(t_ipile pile);
void	ft_free(t_list **pile);
int		ft_getlen(char *str);
int		ft_atoi(char *str);
void	ft_init_pile(int argc, char **argv, t_list **pile);

/**	_________________ INFO _________________ **/
void	ft_init_ipile(t_ipile *ipile);
void	ft_get_fpile(t_list **pile, t_ipile *info);
void	ft_get_salpile(t_list **pile, t_ipile *info);
void	ft_get_info(t_list **pile, t_ipile *info);

#endif