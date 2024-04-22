/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:15:56 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 10:15:57 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADD_BONUS_H
# define FT_ADD_BONUS_H

# include <stdarg.h>
# include "ft_dependencies_bonus.h"

// int		ft_add_str(char *text, char *str);
// int		ft_add_unb(char *text, unsigned long nb, char *base);
// int		ft_add_nb(char *text, long nb);
// int		ft_add_pointer(char *text, unsigned long nb);
void	ft_add(const char *format, char *text, va_list args);
#endif