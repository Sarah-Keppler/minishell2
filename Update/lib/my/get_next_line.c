/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** Return a real line from a file descriptor.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char *read_text(int fd)
{
    char *str = malloc(sizeof(char) * (READ_SIZE + 1));
    char *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    int rd_value = -1;

    buffer[0] = '\0';
    if (NULL == str)
        return (NULL);
    while ((rd_value = read(fd, str, READ_SIZE)) == READ_SIZE) {
        if (rd_value == -1 || rd_value == EOF)
            return (NULL);
        str[READ_SIZE] = '\0';
        if (NULL == (buffer = my_strcat_malloc(buffer, str)))
            return (NULL);
    }
    if (0 == rd_value && '\0' == buffer[0])
        return (NULL);
    str[rd_value] = '\0';
    buffer = my_strcat_malloc(buffer, str);
    free(str);
    return (buffer);
}

static char *get_line(char *src, int *times)
{
    char *line = malloc(sizeof(char) * (my_strlen(src) + 2));

    if (NULL == line)
        return (NULL);
    if ((*times) >= my_strlen(src)) {
        line[0] = '\0';
        return (NULL);
    }
    for (int i = 0; '\n' != src[*times] && src[*times]; ++(*times)) {
        line[i] = src[*times];
        line[i + 1] = '\0';
        ++i;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static int times = 0;
    static char *buffer = NULL;
    char *line = NULL;

    if (-1 == fd)
        return (NULL);
    if (NULL == buffer) {
        buffer = read_text(fd);
        if (NULL == buffer)
            return (NULL);
    }
    if (buffer[0])
        line = get_line(buffer, &times);
    else
        return (buffer);
    if (NULL == line)
        return (NULL);
    ++times;
    return (line);
}
