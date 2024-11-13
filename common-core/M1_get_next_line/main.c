#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    (void)ac;
    int i = 0;
    int fd = open(av[1], O_RDONLY);
    
    printf("BUFFER_SIZE=%i\n", BUFFER_SIZE);
    // if (fd == -1) {
    //     perror("Error opening file");
    //     return 1;
    // }

    // Call the function
    char *content;

    content = get_next_line(fd);
    printf("first : %s", content);
    while (i < 10 && content != NULL)
    {
        free(content);
        content = get_next_line(fd);
        printf("line :%s", content);
        i++;
    }
    free(content);
    // content = get_next_line(fd);
    // printf("first : %s", content);
    // free(content);
    // Close the file descriptor
    close(fd);
    return 0;
}