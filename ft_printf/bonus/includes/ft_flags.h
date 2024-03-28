/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:57:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/18 14:29:29 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

# include "ft_printf.h"
# include "function.h"

void	ft_len_flag_str(t_value *value);
void	ft_len_flag_number(t_value *value, char *tmp);
void	ft_width_flag(t_value *value);
void	ft_get_flags(t_value *value, char *desc);
#endif