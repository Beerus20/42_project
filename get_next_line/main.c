#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"



int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	if (!fd)
		return (0);
	printf("VALUE	: [%s]\n\n", get_next_line(fd));
	printf("VALUE	: [%s]\n\n", get_next_line(fd));
	printf("VALUE	: [%s]\n\n", get_next_line(fd));
	printf("VALUE	: [%s]\n\n", get_next_line(fd));
	printf("VALUE	: [%s]\n\n", get_next_line(fd));
	printf("VALUE	: [%s]\n\n", get_next_line(fd));
	close(fd);
	return (0);
}