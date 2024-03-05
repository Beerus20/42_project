/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruce <bruce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:37:41 by bruce             #+#    #+#             */
/*   Updated: 2024/03/05 17:08:37 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

typedef enum e_in_type
{
	INT,
	DOUBLE,
	U_DOUBLE,
	LOW_C_HEX,
	UP_C_HEX,
	CHAR,
	STR,
	TEXT
}	t_in_type;

typedef struct s_action
{
	char	type;
	char	*flags;
}	t_action;

int			ft_count_char(const char *str, const char c);
t_action	ft_init_action(void);

/** --------------------------------------
 ** TMP function
*/
void		ft_show_value(t_action *action);
// ---------------------------------------

#endif
