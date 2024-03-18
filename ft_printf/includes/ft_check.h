/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:21:25 by beerus            #+#    #+#             */
/*   Updated: 2024/03/18 14:28:43 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include "function.h"

int	ft_check_type(char c);
int	ft_isint(char type);
int	ft_isuint(char type);
int	ft_isflag(int c);
int	ft_isnumber(char type);
#endif