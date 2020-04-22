/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Return a string followed by another.
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

void my_strcat(char *dest, char const *src)
{
    int i = 0;
    int di = my_strlen(dest);

    while ('\0' != src[i]) {
        dest[di] = src[i];
        ++di;
        ++i;
    }
    dest[di] = '\0';
}

char *my_strcat_malloc(char *src2, char const *src)
{
    int di = my_strlen(src2);
    char *str = malloc(sizeof(char) * (my_strlen(src2) + my_strlen(src) + 1));

    if (NULL == str)
        return (NULL);
    for (int i = 0; src2[i]; ++i)
        str[i] = src2[i];
    for (int i = 0; src[i]; ++i) {
        str[di] = src[i];
        ++di;
    }
    str[di] = '\0';
    free(src2);
    return (str);
}
