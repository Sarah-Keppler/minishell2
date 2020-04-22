/*
** EPITECH PROJECT, 2019
** my_math
** File description:
** My own math.h
*/

#include "my.h"

int my_pow(int nb, int power)
{
    if (0 > power)
        return (0);
    if (0 == power)
        return (1);
    if (1 < power) {
        nb *= my_pow(nb, power - 1);
        return (nb);
    }
    return (nb);
}

static char my_char_isnum(char c)
{
    if ('0' <= c && '9' >= c)
        return ('0');
    else
        return ('1');
}

static long my_parse_nbr(char const *str, long nbr)
{
    int delta_char_to_num = 48;
    long limit = 2147483647;

    while (*str && '0' == my_char_isnum(*str)) {
        nbr = nbr * 10 + (*str - delta_char_to_num);
        if (limit < nbr)
            break;
        ++str;
    }
    return (nbr);
}

int my_getnbr(char const *str)
{
    long nbr = 0;
    int n_minuses = 0;
    long limit = 2147483647;

    while (*str && !(nbr)) {
        if (*str == '-')
            ++n_minuses;
        else if (my_char_isnum(*str))
            nbr = my_parse_nbr(str, nbr);
        if (nbr > limit)
            return (0);
        str++;
    }
    if (0 != n_minuses % 2)
        nbr *= -1;
    else
        nbr *= 1;
    return (nbr);
}
