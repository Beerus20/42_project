/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:07:29 by ballain           #+#    #+#             */
/*   Updated: 2024/03/18 14:29:29 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_H
# define FT_GET_H

# include "ft_printf.h"
# include "function.h"

char	*ft_get_value(char type, va_list args);
void	*ft_get_str_value(char *value);
void	*ft_get_int_value(char type, int value);
char	*ft_get_uint_value(char type, va_list args);
#endif