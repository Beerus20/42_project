/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:07:55 by ballain           #+#    #+#             */
/*   Updated: 2024/03/18 00:12:03 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_printf.h"
# include "libft.h"

void	*ft_stoc(int c);
void	ft_show_value(t_value *value);
void	ft_show_test(t_value *value);
int		ft_hasflag(char *flag);
void	ft_add_front_content_value(t_value *value, char *str);
#endif