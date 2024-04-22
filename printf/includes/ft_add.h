/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:50 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 10:20:15 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADD_H
# define FT_ADD_H

# include <stdio.h>
# include <stdarg.h>
# include "ft_get_len.h"

int		ft_add_char(char *text, char c);
int		ft_add_str(char *text, char *str);
int		ft_add_unb(char *text, unsigned long nb, int type);
int		ft_add_nb(char *text, long nb);
int		ft_add_pointer(char *text, unsigned long nb);
void	ft_add(const char *format, char *text, va_list args);
#endif