/*
** EPITECH PROJECT, 2019
** my_read
** File description:
** Read files.
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"

char *read_a_file_with_stat(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = NULL;
    struct stat sb;

    if (-1 == fd) {
        my_puterror("The argument need to be a file\n");
        return (NULL);
    }
    if (0 == stat(file, &sb)) {
        buffer = malloc(sizeof(char) * (sb.st_size + 1));
        if (NULL == buffer)
            return (NULL);
        read(fd, buffer, sb.st_size);
    } else
        return (NULL);
    buffer[sb.st_size] = '\0';
    close(fd);
    return (buffer);
}

char *read_a_file(int fd, int read_size)
{
    char *piece = malloc(sizeof(char) * (read_size + 1));
    char *buffer = malloc(sizeof(char) * (read_size + 1));
    int rd_value = -1;

    if (NULL == piece || NULL == buffer)
        return (NULL);
    buffer[0] = '\0';
    while (read_size == (rd_value = read(fd, piece, read_size))) {
        if (-1 == rd_value || rd_value == EOF)
            return (NULL);
        piece[read_size] = '\0';
        if (NULL == (buffer = my_strcat_malloc(buffer, piece)))
            return (NULL);
    }
    if (0 == rd_value && '\0' == buffer[0])
        return (NULL);
    piece[rd_value] = '\0';
    buffer = my_strcat_malloc(buffer, piece);
    free(piece);
    return (buffer);
}
