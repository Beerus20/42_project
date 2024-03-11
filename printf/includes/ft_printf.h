/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:21:50 by beerus            #+#    #+#             */
/*   Updated: 2024/03/11 15:55:42 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "ft_check.h"
# include "ft_utils.h"

int	ft_print_int(char type, int nb);
int	ft_print_u(char type, va_list args);
int	ft_print_str(char *str);
int	ft_print_pointer(void *pointer);
int	ft_printf(const char *format, ...);
#endif
