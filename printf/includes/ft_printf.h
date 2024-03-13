/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:21:50 by beerus            #+#    #+#             */
/*   Updated: 2024/03/13 19:38:34 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "ft_check.h"
# include "ft_utils.h"

int	ft_print_flags(char type, char *desc, void *str);
int	ft_print_int(char type, char *desc, int nb);
int	ft_print_u(char type, char *desc, va_list args);
int	ft_print_str(char type, char *desc, char *str);
int	ft_print_pointer(void *pointer);
int	ft_printf(const char *format, ...);
#endif
