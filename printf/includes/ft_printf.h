/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:14 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 14:24:29 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_add_bonus.h"
# include "ft_dependencies_bonus.h"

int	ft_len_value(char *type, va_list args);
int	ft_get_len(const char *format, va_list args);
int	ft_printf(const char *format, ...);
#endif