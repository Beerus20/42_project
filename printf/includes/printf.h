/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruce <bruce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:37:41 by bruce             #+#    #+#             */
/*   Updated: 2024/03/04 21:36:00 by bruce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

# define TYPE(x) _Generic((x),\
	int: "int",\
	int*: "Pointer int",\
	short: "short",\
	long: "long",\
	char: "char",\
	float: "float",\
	double: "double",\
	default: "unknown"\
)(x)

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

typedef struct s_in_value
{
	t_in_type			type;
	char				flag;
	void				*content;
	struct s_in_value	*next;
}	t_in_value;

int		ft_count_char(const char *str, const char c);

/** --------------------------------------
 ** TMP function
*/
void	ft_show_value(t_in_value *lst);
// ---------------------------------------

#endif