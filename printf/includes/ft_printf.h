/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:46:38 by ballain           #+#    #+#             */
/*   Updated: 2024/03/14 09:49:38 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "ft_check.h"
# include "ft_utils.h"

void	ft_rprintc(char c, int len);
int		ft_print_flags(char type, char *desc, void *str);
int		ft_print_int(char type, char *desc, int nb);
int		ft_print_u(char type, char *desc, va_list args);
int		ft_print_str(char type, char *desc, char *str);
int		ft_print_pointer(void *pointer);
int		ft_printf(const char *format, ...);
#endif
