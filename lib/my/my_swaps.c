/*
** EPITECH PROJECT, 2019
** my_swaps
** File description:
** Swap two ints.
*/

#include "my.h"

void my_swap_int(int *a, int *b)
{
    int save = *b;

    *b = *a;
    *a = save;
}

void my_swap_char(char *start, char *end)
{
    char save = *end;

    *end = *start;
    *start = save;
}
