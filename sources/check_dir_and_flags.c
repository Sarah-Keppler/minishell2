/*
** EPITECH PROJECT, 2019
** cd
** File description:
** Move from a directory to another.
*/

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include "proto.h"

static char check_each_flag(char c)
{
    char *autorized = "plvn";
    int nbr = 0;

    for (int i = 0; autorized[i]; ++i)
        if (c != autorized[i])
            ++nbr;
    if (4 == nbr)
        return ('1');
    return ('0');
}

static char check_cd_back(char **args)
{
    int nbr = 0;
    int index = 0;

    for (int i = 1; args[i]; ++i)
        if ('-' != args[i][0] || ('-' == args[i][0] &&
            1 == my_strlen(args[i]))) {
            index = i;
            ++nbr;
        }
    if (1 != nbr) {
        my_puterror("Usage: cd [-plvn][-|<dir>].\n");
        return ('1');
    }
    if (0 == my_strcmp(args[index - 1], "--") &&
        0 == my_strcmp(args[index], "-")) {
        my_puterror("-: No such file or directory.\n");
    }
    return ('0');
}

static char check_dir(char **args, int nbr, char *dir)
{
    int i = 0;

    if (NULL == dir)
        return ('0');
    if (0 == my_strcmp("-", dir)) {
        if ('1' == check_cd_back(args))
            return ('1');
        return ('0');
    }
    while (args[++i])
        if ('-' != args[i][0] || ('-' == args[i][0] &&
            1 == my_strlen(args[i])))
            break;
    if (nbr != (i + 1)) {
        my_puterror("cd: Too many arguments.\n");
        return ('1');
    }
    return ('0');
}

char check_dir_and_flags(command_t *command, char *dir, char *flags)
{
    for (int i = 1; command->args[i]; ++i)
        if (0 == my_strncmp("--", command->args[i], 2) &&
            2 != my_strlen(command->args[i])) {
            my_puterror("Usage: cd [-plvn][-|<dir>].\n");
            return ('1');
        }
    if ('1' == check_dir(command->args, command->nb_arg, dir)) {
        free(flags);
        return ('1');
    }
    for (int i = 0; flags[i]; ++i)
        if ('1' == check_each_flag(flags[i])) {
            free(flags);
            my_puterror("Usage: cd [-plvn][-|<dir>].\n");
            return ('1');
        }
    return ('0');
}
