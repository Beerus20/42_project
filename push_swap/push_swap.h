#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./printf/includes/ft_printf.h"

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
	int	*len;
}	t_ipile;

/**	_________________ MOUVEMENT _________________ **/
void	ft_swap(t_list **pile, t_ipile *ipile);
void	ft_push(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib);
void	ft_rotate(t_list **pile, t_ipile *ipile);
void	ft_rev_rotate(t_list **pile, t_ipile *ipile);

/**	_________________ UTILS _________________ **/
t_list	*ft_get_last(t_list *pile);
void	ft_show(char *title, t_list *pile_a, t_list *pile_b);
void	ft_show_ipile(t_ipile pile_a, t_ipile pile_b);
void	ft_free(t_list **pile);
void	ft_free_info(t_ipile *ipile);
int		ft_getlen(char *str);
int		ft_atoi(char *str);
void	ft_init_pile(int argc, char **argv, t_list **pile);

/**	_________________ INFO _________________ **/
void	ft_init_ipile(t_ipile *ipile);
void	ft_get_fpile(t_list **pile, t_ipile *info);
void	ft_get_salpile(t_list **pile, t_ipile *info);
void	ft_get_info(t_list **pile, t_ipile *info);

/**	_________________ ANALYSES _________________ **/
int		ft_check_isgreater(t_list **pile, t_ipile *ipile);
int		ft_check_isgreater_inv(t_list **pile, t_ipile *ipile);
int		ft_check(t_list *pile, int argc);
int		ft_check_alignement(t_list *pile, int direction);
int		ft_search_position(t_list *pile, int value);

/**	_________________ ACTION _________________ **/
int		ft_action_isgreater(t_list **pile, t_ipile *ipile);
int		ft_is_both_aligned(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib);
int		ft_arrange_pile(t_list **pile, t_ipile *ipile);
int		*ft_count_move(t_list **pile, t_ipile *ia, t_ipile *ib);
int		ft_add_in_position(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib);

#endif