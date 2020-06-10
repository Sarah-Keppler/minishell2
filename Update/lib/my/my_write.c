/*
** EPITECH PROJECT, 2019
** my_write
** File description:
** Display a char, a string and an error.
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char const c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; ++i)
        my_putchar(str[i]);
}

void my_write(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
}
