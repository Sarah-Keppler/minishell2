/*
** EPITECH PROJECT, 2019
** str_manipulation
** File description:
** Get and set different informations of a str.
*/

#include <stddef.h>
#include "my.h"

int my_strlen(char const *str)
{
    int number = 0;

    while ('\0' != *str) {
        ++str;
        ++number;
    }
    return (number);
}

void my_revstr(char *str)
{
    char *end = str + my_strlen(str) - 1;
    char *start = str;

    while (start < end) {
        my_swap_char(start, end);
        --end;
        ++start;
    }
}

static int match(char const *str, char const *to_find, int i)
{
    int number = 0;
    int g = 0;

    while (to_find[g] == str[i] && '\0' != str[i]) {
        ++number;
        ++g;
        ++i;
    }
    if (number == my_strlen(to_find))
        return (1);
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] == to_find[0] && match(str, to_find, i))
            return (str + i);
    return (NULL);
}

void my_int_to_str(int number, char *str)
{
    int f = 0;
    int figure;

    while (number != 0) {
        figure = number % 10;
        number /= 10;
        str[f] = figure + 48;
        str[f + 1] = '\0';
        ++f;
    }
}
