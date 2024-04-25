#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int	*first;
	int	*second;
	int	*last;
	int	*len;
}	t_info;

typedef struct s_pile
{
	t_list	**a;
	t_list	**b;
	t_info	*ia;
	t_info	*ib;
}	t_pile;

/**	_________________ MOUVEMENT _________________ **/
void	ft_swap(t_list **pile);
void	ft_push(t_pile *pile, int inv);
void	ft_rotate(t_list **pile);
void	ft_rev_rotate(t_list **pile);


/**	_________________ INFO _________________ **/
int		ft_get_list_len(t_list *pile);
void	ft_get_fpile(t_list **pile, t_info *info);
void	ft_get_salpile(t_list **pile, t_info *info);
void	ft_init_info(t_info *pile);
void	ft_get_info(t_list **pile, t_info *info);

/**	_________________ FREE _________________ **/
void	ft_show_ipile(t_pile pile);
void	ft_show(t_pile pile);

/**	_________________ FREE _________________ **/
void	ft_free_info(t_info *info);
void	ft_free(t_list **pile);

/**	_________________ EXECUTION _________________ **/
int		exec(t_pile *pile, char *action);

/**	_________________ INIT _________________ **/
void	 ft_init_pile(int argc, const char **argv, t_list **pile);
t_pile	*ft_init_piles(int argc, const char **argv);

#endif