/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:42:41 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 12:42:48 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../push_swap.h"

typedef struct s_cmd
{
	char			*content;
	struct s_cmd	*next;
}	t_cmd;

char	*ft_strchr(char *str, int c);
int		ft_gnl_strlen(char *str);
int		ft_gnl_get_len(t_cmd *value);
char	*ft_alloc(char *s, int len);
void	ft_gnl_free(t_cmd *value);
char	*get_next_line(int fd);
#endif
