/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:21:57 by beerus            #+#    #+#             */
/*   Updated: 2024/03/13 23:28:54 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdarg.h>
# include "libft.h"
# include "ft_check.h"

typedef struct s_flags
{
	char	*flag;
	int		min_w;
	int		max_w;
}	t_flags;

int		ft_count(const char *str, int (*f)(char));
int		ft_count_flags(char *desc);
void	ft_split_width(char **w, char *desc);
int		ft_count_nb(char type, unsigned long nb);
void	ft_uitos(char type, unsigned long nb, char *value);
void	ft_iflags(t_flags *flags, char *flag, int min, int max);
void	ft_get_flags(char *desc, t_flags *flags);
void	ft_get_desc(char *desc, const char *str, int len);
void	*ft_init_to_printv(char type, t_flags *flags, void *str);
int		ft_apply_flags(char type, t_flags *flags, void *str);
void	ft_dash_flag(char type, int apply, int len, void *c);
#endif