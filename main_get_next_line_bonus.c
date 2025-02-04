#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check if correct number of arguments are passed
    if (argc < 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    // Open the files passed as command-line arguments
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);

    if (fd1 == -1 || fd2 == -1) {
        printf("Error opening files.\n");
        return 1;
    }

    char *str;

    // Read lines from the first file
    printf("Reading from %s:\n", argv[1]);
    while ((str = get_next_line(fd1)) != NULL) {
        printf("%s", str);
        free(str);
    }

    // Read lines from the second file
    printf("Reading from %s:\n", argv[2]);
    while ((str = get_next_line(fd2)) != NULL) {
        printf("%s", str);
        free(str);
    }

    // Close the file descriptors
    close(fd1);
    close(fd2);

    return 0;
}

