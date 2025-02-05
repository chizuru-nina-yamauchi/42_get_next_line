#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	while (str = get_next_line(fd))
	{
		printf("%s\n", str);
		free(str);
	}
	printf("%s\n", str);
	close(fd);
}

