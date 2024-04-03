/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:07:55 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:06:21 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

# include "ft_printf_bonus.h"
# include "function.h"

int		ft_is_null_hex_value(char *content);
int		ft_has_extra_flags(char *flags, char *str);
int		ft_zero_flag_condition(t_value *value);
void	*ft_stoc(int c);
int		ft_hasflag(char *flag);
void	ft_add_front_content_value(t_value *value, char *str);
#endif