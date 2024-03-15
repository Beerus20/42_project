/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:07:29 by ballain           #+#    #+#             */
/*   Updated: 2024/03/15 16:07:53 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_H
# define FT_GET_H

# include "ft_printf.h"
# include "libft.h"

char	*ft_get_value(char type, va_list args);
char	*ft_get_str_value(char *value);
void	*ft_get_int_value(char type, int value);
char	*ft_get_uint_value(char type, va_list args);
#endif