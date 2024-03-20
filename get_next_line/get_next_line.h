#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_getline
{
	int					fd;
	char				*content;
	struct s_getline	*next;
}	t_getline;

char	*get_next_line(int fd);
#endif
