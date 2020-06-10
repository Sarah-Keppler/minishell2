/*
** EPITECH PROJECT, 2019
** tab_and_spaces
** File description:
** Remove useless tabs and spaces.
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static void remove_after_word(char *src)
{
    int pos = 0;

    for (int i = 0; src[i]; ++i)
        if ('\t' != src[i] && ' ' != src[i] && '\n' != src[i])
            pos = i;
    src[pos + 1] = '\0';
}

static char *copy_without_tab_and_space(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    char swt = '0';
    int y = 0;

    if (NULL == str)
        return (NULL);
    for (int i = 0; src[i]; ++i)
        if (('\t' == src[i] || ' ' == src[i]) && '1' == swt) {
            swt = '0';
            str[y] = ' ';
            ++y;
        } else if ('\t' != src[i] && ' ' != src[i]) {
            swt = '1';
            str[y] = src[i];
            ++y;
        }
    str[y] = '\0';
    return (str);
}

char *remove_space_and_tab(char const *src)
{
    char *str = copy_without_tab_and_space(src);

    if (NULL == str)
        return (NULL);
    remove_after_word(str);
    return (str);
}
