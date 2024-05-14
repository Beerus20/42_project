#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdlib.h>
# include <stdarg.h>
# include "./printf/includes/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	int	first;
	int	second;
	int	last;
	int	len;
}	t_info;

typedef struct s_pile
{
	t_list	**a;
	t_list	**b;
	t_info	*ia;
	t_info	*ib;
}	t_pile;

/**	_________________ TRANSFORM _________________ **/
void	ft_transform_value(t_pile *pile);

/**	_________________ MOUVEMENT _________________ **/
void	ft_swap(t_list **pile);
void	ft_push(t_pile *pile, int inv);
void	ft_rotate(t_list **pile);
void	ft_rev_rotate(t_list **pile);

/**	_________________ INFO _________________ **/
t_list	*ft_get_last(t_list *pile);
void	ft_get_info(t_list **pile, t_info *info);
void	ft_update_info(t_pile *pile);
int		ft_info(t_info info, int id);

/**	_________________ UTILS _________________ **/
int		request(t_pile *pile, int question, char *to_do);
int		request_loop(t_pile *pile, int question, int nb_iter ,char *to_do);
void	ft_show_info(t_pile pile);
void	ft_show(t_pile pile);
void	ft_show_pile(t_list *pile);
void	ft_show_test(t_list *pile, int *tab);
void	ft_show_diff(t_list *pile, t_list *tmp_pile);

/**	_________________ LIST UTILS _________________ **/
t_list	*ft_init_list(int value);
int		ft_get_list_len(t_list *pile);
void	ft_pop(t_list **pile);
void	ft_add_front(t_list **pile, t_list *new);
void	ft_del_front(t_list **pile);
void	ft_add_back(t_list **pile, t_list *new);

/**	_________________ FREE _________________ **/
void	ft_free_list(t_list *pile);
void	ft_free(t_list **pile);
void	ft_free_pile(t_pile *pile);

/**	_________________ EXECUTION _________________ **/
int		exec(t_pile *pile, char *action);
void	loop_exec(t_pile *pile, int nb_iter, char *to_do);

/**	_________________ INIT _________________ **/
void	ft_init_pile(int argc, const char **argv, t_list **pile);
t_pile	*ft_init_piles(int argc, const char **argv);

/**	_________________ CHECK _________________ **/
int		ft_check_isbigger(t_list *pile, int nb);
int		ft_check_issmaller(t_list *pile, int nb);
int		ft_check_increas(t_list *pile);
int		ft_check_decreas(t_list *pile);
int		ft_check_isalign(t_list *pile);
int		ft_check_percent(t_pile *pile, int (*function)(t_list *), int index);

/**	_________________ GETTERS _________________ **/
int		ft_get_min_value(t_list *pile);
int		ft_get_max_value(t_list *pile);
int		ft_get_value(t_list *pile, int index);
int		ft_get_index(t_list *pile, int value);

/**	_________________ ACTION _________________ **/
int		ft_search(t_list *pile, int value);
int		ft_arrange(t_pile *pile);
int		ft_position_of(t_list *pile, int value);
int		ft_get_position(t_list *pile, int value, int behind);
int		ft_action(t_pile *pile, t_list *ref);

/**	_________________ ADD STACK _________________ **/
void	ft_move_a(t_pile *pile, t_list *list);
void	ft_add_to_a(t_pile *pile);
void	ft_add_to_b(t_pile *pile);

/**	_________________ INCREASE_UTILS _________________ **/
t_list	*ft_upper_nb(t_list *pile, int value);
int		ft_get_maxv_tab(int *tab, int len);
int		*ft_init_ids(int nb);
int		*ft_init_tab(t_list *pile);
int		*ft_get_tab_ids(t_list *pile);

/**	_________________ INCREASE _________________ **/
int		ft_get_nbmax_composition(t_list *pile);
int		ft_check_begin_max_increase(t_list *pile);
t_list	*ft_get_max_increase(t_list *pile);


t_list	*ft_get_sub_list_sup(t_list *pile, int begin, int end, int value);
#endif