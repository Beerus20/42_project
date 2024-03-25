#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		ft_strlen(char *str);
char	*ft_zalloc(int n);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
#endif
