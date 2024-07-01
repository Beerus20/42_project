/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:38:11 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 20:06:36 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef BONUS
#  define BONUS 0
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./printf/includes/ft_printf.h"

typedef struct s_list
{
	long			content;
	struct s_list	*next;
}	t_list;

typedef struct s_action
{
	char	*end_action;
	int		(*fa)(t_list *, int);
	int		(*fb)(t_list *, int);
}	t_action;

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

/**	_________________ PARAMS _________________ **/
char		**ft_split(char const *s, char c);
int			ft_params_is_valid(int argc, const char **argv);
int			ft_check_error(t_list *pile);

/**	_________________ TRANSFORM _________________ **/
void		ft_transform_value(t_pile *pile);

/**	_________________ MOUVEMENT _________________ **/
void		ft_swap(t_list **pile);
void		ft_push(t_pile *pile, int inv);
void		ft_rotate(t_list **pile);
void		ft_rev_rotate(t_list **pile);

/**	_________________ INFO _________________ **/
t_list		*ft_get_last(t_list *pile);
void		ft_get_info(t_list **pile, t_info *info);
void		ft_update_info(t_pile *pile);
int			ft_info(t_info info, int id);

/**	_________________ UTILS _________________ **/
t_list		*ft_get_portion(t_list *pile, t_list *ref);
t_list		*ft_sub_list(t_list *list, int begin, int end);
t_list		*ft_sub_list_between(t_list *list, int a, int b);
int			request(t_pile *pile, int question, char *to_do);
int			request_loop(t_pile *pile, int question, int nb_iter, char *to_do);

/**	_________________ LIST FUNCTIONS _________________ **/
void		ft_add_front(t_list **pile, t_list *new);
void		ft_del_front(t_list **pile);
t_list		*ft_init_list(int value);
void		ft_add_back(t_list **pile, t_list *new);
t_list		*ft_copy_list(t_list *list);

/**	_________________ LIST UTILS _________________ **/
t_list		*ft_move_to(t_list *pile, int value);
void		ft_add_list_value(t_list **list, int index, int value);
void		ft_add_back_content(t_list **pile, long value);
void		ft_del_list_value(t_list **list, int value);
void		ft_concat_list(t_list **a, t_list **b, t_list *s_a, t_list *s_b);

/**	_________________ EXECUTION UTILS _________________ **/
void		ft_exec_swap(t_pile *pile, char type);
void		ft_exec_push(t_pile *pile, char type);
void		ft_exec_rotate(t_pile *pile, char type);
void		ft_exec_rev_rotate(t_pile *pile, char type);

/**	_________________ EXECUTION _________________ **/
int			exec(t_pile *pile, char *action);
void		loop_exec(t_pile *pile, int nb_iter, char *to_do);

/**	_________________ INIT _________________ **/
int			ft_verify(t_pile *pile, t_pile *ref);
int			ft_init_pile(int argc, const char **argv, t_list **pile);
t_pile		*ft_init(void);

/**	_________________ CHECK _________________ **/
int			ft_check_increas(t_list *pile);
int			ft_search(t_list *pile, int value);
int			ft_position(t_list *pile, int position);
int			ft_get_position(t_list *pile, int value);
int			ft_get_position_inv(t_list *pile, int value);

/**	_________________ GETTERS _________________ **/
int			ft_get_min_value(t_list *pile);
int			ft_get_max_value(t_list *pile);
int			ft_get_value(t_list *pile, int index);
int			ft_get_index(t_list *pile, int value);
int			ft_get_list_len(t_list *pile);

/**	_________________ ACTION UTILS _________________ **/
int			ft_abs(int value);
int			ft_nbmv(t_list *pile, int position);
int			ft_select_mvl_v(t_pile *pile, t_list *sub_pile, t_action action);
int			ft_extra_moves(int *p_a, int *p_b);
t_action	ft_init_action(int type);

/**	_________________ ACTION _________________ **/
int			ft_search(t_list *pile, int value);
int			ft_action(t_pile *pile, t_pile *ref);

/**	_________________ ADD STACK _________________ **/
int			ft_rectification_ref(t_list	*pile, t_list *ref);
int			ft_check_additional_ref(t_list *pile, t_list *ref);
t_list		*ft_get_extra(t_list *pile, t_list *ref);
void		ft_move(t_pile *pile, int p_a, int p_b);
void		ft_move_element(t_pile *pile, t_list *sub_pile, t_action action);

/**	_________________ INCREASE_UTILS _________________ **/
t_list		*ft_upper_nb(t_list *pile, int value);
int			ft_get_maxv_tab(int *tab, int len);
int			*ft_init_ids(int nb);
int			*ft_init_tab(t_list *pile);
int			*ft_get_tab_ids(t_list *pile);

/**	_________________ INCREASE FUNCTIONS _________________ **/
int			ft_get_nbmax_composition(t_list *pile);
int			ft_check_begin_max_increase(t_list *pile);

/**	_________________ INCREASE _________________ **/
t_list		*ft_get_max_increase(t_list *pile);

/**	_________________ SHOW _________________ **/
void		ft_show_info(t_pile pile);
void		ft_show(t_pile pile);
void		ft_show_pile(t_list *pile);
void		ft_show_diff(t_list *pile, t_list *tmp_pile);
void		ft_debug(t_pile pile);

/**	_________________ FREE _________________ **/
void		ft_free_list(t_list *pile);
void		ft_free(t_list **pile);
void		ft_free_pile(t_pile *pile);
t_list		*ft_clean_list(t_list *list);

#endif