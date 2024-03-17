/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:46:38 by ballain           #+#    #+#             */
/*   Updated: 2024/03/17 10:25:00 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
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

void	ft_printc(t_value *value);
void	ft_apply_flags(t_value *value);
int		ft_printf(const char *format, ...);
#endif
