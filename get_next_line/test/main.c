#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line.h"



int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	if (!fd)
		return (0);
	get_next_line(fd);
	close(fd);
	return (0);
}
