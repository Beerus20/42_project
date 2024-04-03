/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:57:37 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 13:56:08 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_BONUS_H
# define FT_FLAGS_BONUS_H

# include "ft_printf_bonus.h"
# include "function.h"

void	ft_len_flag_str(t_value *value);
void	ft_len_flag_number(t_value *value, char *tmp);
void	ft_width_flag(t_value *value);
void	ft_get_flags(t_value *value, char *desc);
#endif