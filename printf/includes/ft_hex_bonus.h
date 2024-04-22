/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:12 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 10:16:13 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEX_BONUS_H
# define FT_HEX_BONUS_H

# include "ft_utils_bonus.h"

int	ft_get_len_hex(int flags[7], unsigned long nb);
int	ft_add_hex_value(char *text, int flags[7], unsigned long nb, int type);
#endif