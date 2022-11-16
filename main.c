#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;
    char *line;

    (void) argc;
    fd = open(argv[1], O_RDONLY);
    // while (fd)
    // {
        line = get_next_line(fd);
        dprintf(1, "LINE = [%s]\n", line);
        // if (!line)
        // {
        //     // dprintf(1, "AVANT FREE LINE = %s\n", line);
        //     free(line);
        //     // printf("JE SORS AVEC %s\n", line);
        //     break ;
        // }
        // else
            free(line);
        // break ;
    // }
    close(fd);
}