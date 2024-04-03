/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:46:38 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:05:57 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "function.h"
# include "ft_check_bonus.h"
# include "ft_utils_num_bonus.h"
# include "ft_get_bonus.h"

typedef struct s_value
{
	char			type;
	char			*flags;
	char			*content;
	int				w;
	int				l;
	struct s_value	*next;
}	t_value;

int		ft_printf(const char *format, ...);
int		ft_print_value(t_value *value);
t_value	*ft_fill_text_value(t_value *value, char *str, int *len);
t_value	*ft_fill_arg_value(t_value *value, char *str, va_list args, int *len);
void	ft_free_value(t_value *value);
void	ft_printc(t_value *value);
void	ft_apply_flags(t_value *value);
#endif
