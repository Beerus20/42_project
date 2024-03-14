/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:46:38 by ballain           #+#    #+#             */
/*   Updated: 2024/03/14 16:25:30 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "ft_check.h"
# include "ft_utils.h"
# include "ft_utils_num.h"

typedef struct s_value
{
	char		type;
	char		*flags;
	char		*content;
	int		w;
	int		l;
	struct s_value	*next;
}	t_value;

int		ft_printf(const char *format, ...);
#endif
