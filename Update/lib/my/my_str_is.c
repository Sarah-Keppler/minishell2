/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** Check if a str is a integer or float (+ or -);
*/

#include "my.h"

char my_str_isnum(char const *str)
{
    while ('\0' != *str) {
        if (!('0' <= *str && '9' >= *str))
            return ('1');
        ++str;
    }
    return ('0');
}

char my_str_isnum_with_neg(char const *str)
{
    while ('\0' != *str) {
        if (!('0' <= *str && '9' >= *str) && '-' != *str)
            return ('1');
        ++str;
    }
    return ('0');
}

char my_str_isint_float(char const *str)
{
    int point = 0;
    int neg = 0;

    if (1 == my_strlen(str) && (str[0] == '.' || str[0] == '-'))
        return ('1');
    while ('\0' != *str) {
        if (!('0' <= *str && '9' >= *str) && '-' != *str && '.' != *str)
            return ('1');
        if ('.' == *str)
            ++point;
        if ('-' == *str)
            ++neg;
        ++str;
    }
    if (1 < neg || 1 < point)
        return ('1');
    return ('0');
}
