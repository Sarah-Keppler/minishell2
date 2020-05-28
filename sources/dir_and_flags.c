/*
** EPITECH PROJECT, 2019
** cd
** File description:
** Move from a directory to another.
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "proto.h"

char *get_directory(command_t *command)
{
    char *dir = NULL;

    for (int i = 1; command->args[i]; ++i)
        if ('-' != command->args[i][0] || ('-' == command->args[i][0] &&
            1 == my_strlen(command->args[i]))) {
            dir = command->args[i];
            break;
        }
    return (dir);
}

static char check_already_in(char *flags, char c)
{
    for (int i = 0; flags[i]; ++i)
        if (c == flags[i])
            return ('0');
    return ('1');
}

static void recup_flag(char *flags, char *arg)
{
    int i = -1;

    while (flags[++i]);
    for (int s = 1; arg[s]; ++s) {
        if ('0' == check_already_in(flags, flags[s]))
            continue;
        flags[i] = arg[s];
        flags[++i] = '\0';
    }
}

char *get_flags(command_t *command)
{
    char *flags = NULL;
    int nbr = 0;

    for (int i = 1; command->args[i]; ++i)
        if ('-' == command->args[i][0])
            ++nbr;
    flags = malloc(sizeof(char) * (nbr + 1));
    if (NULL == flags)
        return (NULL);
    flags[nbr] = '\0';
    if (0 == nbr)
        return (flags);
    flags[0] = '\0';
    for (int i = 1; command->args[i]; ++i)
        if ('-' == command->args[i][0] && '-' != command->args[i][1])
            recup_flag(flags, command->args[i]);
    return (flags);
}
