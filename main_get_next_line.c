#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int	fd;
	char	*line;
	
	// test 1
	fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Test case 1: File with multiple lines:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n");
	
	// test 2
	fd = open("single_line_file.txt", ORDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Test case 2: File with a single line:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n");
	
	// test 3
	fd = open("empty_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Test case 3: Empty file:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n");
	
	// test 4
	fd = open("no_newline_file.txt", ORDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Test case 4: File without newlines:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n");
	
	// test 5
	fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Test case 5: EOF testing:\n");
	line = get_next_line(fd); // first call to get a line
	if (line != NULL)
	{
		printf("Line 1: %s", line);
		free(line);
	}
	line = get_next_line(fd); // second call to get the next line
	if (line != NULL)
	{
		printf("Line 2: %s", line);
		free(line);
	}
	line = get_next_line(fd); // third call, this should return NULL
	if (line == NULL)
	{
		printf("EOF reached!!!\n");
	}
	close(fd);
	printf("\n");
	
	// test 6
	fd = open("one_char_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	printf("Test case 6: File with just one character:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	printf("\n");
	return (0);
}
