/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:37:41 by bruce             #+#    #+#             */
/*   Updated: 2024/03/08 20:38:18 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_descriptor
{
	char	type;
	char	*flags;
}	t_descriptor;

int				ft_nblen(unsigned long nb, int base);
char			*ft_rev_str(char *str);
t_descriptor	ft_init_descriptor(void);
void			ft_decimal_to_str(float nb);
char			*ft_get_address(void *p);
void			ft_base_tth(int n, char type);
int				ft_printf(const char *format, ...);

#endif
