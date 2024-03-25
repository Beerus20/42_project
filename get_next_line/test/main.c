#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line.h"



int	main(void)
{
	int		fd;
	char  *line;

	fd = open("text.txt", O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	printf("result	: %s",line);
	free(line);

	line = get_next_line(fd);
	printf("result	: %s",line);
	free(line);

	close(fd);
	return (0);
}
