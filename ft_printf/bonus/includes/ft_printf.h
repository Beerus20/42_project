/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:46:38 by ballain           #+#    #+#             */
/*   Updated: 2024/03/18 14:28:24 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "function.h"
# include "ft_check.h"
# include "ft_utils_num.h"
# include "ft_get.h"

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
