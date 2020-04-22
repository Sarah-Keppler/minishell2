/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Copy a string into another.
*/

#include "my.h"

void my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while ('\0' != src[i]) {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

void my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != src[n]) {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}
