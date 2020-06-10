/*
** EPITECH PROJECT, 2019
** Prompt
** File description:
** Print the prompt depending of pwd.
*/

#include <unistd.h>
#include "proto.h"

void print_prompt(void)
{
    if (!isatty(0))
        return;
    my_putstr("$>");
}
