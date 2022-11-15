#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int	fd;
	char	*line;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Nope");
	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
}
