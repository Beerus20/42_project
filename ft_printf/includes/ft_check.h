/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:21:25 by beerus            #+#    #+#             */
/*   Updated: 2024/03/17 09:06:51 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include "libft.h"

int	ft_check_type(char c);
int	ft_isint(char type);
int	ft_isuint(char type);
int	ft_isflag(int c);
int	ft_isnumber(char type);
#endif