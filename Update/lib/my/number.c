/*
** EPITECH PROJECT, 2019
** number
** File description:
** Check many thongs link to numbers.
*/

#include "my.h"

int get_nb_of_time_char_appears(char *src, char c)
{
    int count = 0;

    for (int i = 0; '\0' != src[i]; ++i)
        if (c == src[i])
            ++count;
    return (count);
}

int get_nb_of_digits(int nb)
{
    int count = 0;

    if (0 == nb)
        return (1);
    while (nb != 0) {
        nb /= 10;
        ++count;
    }
    return (count);
}
