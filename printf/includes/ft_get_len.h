/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:54 by ballain           #+#    #+#             */
/*   Updated: 2024/04/20 12:50:06 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_LEN_H
# define FT_GET_LEN_H

# include <stdarg.h>

int	ft_strlen(char *str);
int	ft_u_nblen(unsigned long nb, int base);
int	ft_nblen(long nb);
int	ft_len_value(char *type, va_list args);
#endif