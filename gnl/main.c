#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;
    argc = 0;

    fd = open(argv[1], O_RDONLY);
    while(get_next_line(fd, &line))
    {
        printf("%s\n",line);
        free(line);
    }
    free(line);
    return(0);
}