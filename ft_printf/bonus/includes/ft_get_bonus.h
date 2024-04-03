/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:07:29 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:05:36 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_BONUS_H
# define FT_GET_BONUS_H

# include "ft_printf_bonus.h"
# include "function.h"

char	*ft_get_value(char type, va_list args);
void	*ft_get_str_value(char *value);
void	*ft_get_int_value(char type, int value);
char	*ft_get_uint_value(char type, va_list args);
#endif