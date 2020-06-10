/*
** EPITECH PROJECT, 2019
** cd
** File description:
** Move from a directory to another.
*/

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "proto.h"

static char special_cd(shell_t *shell, command_t *command, char *dir)
{
    char *path[3] = {"~", "~/", "-"};
    char (*cd_path[3])(shell_t *, command_t *) = {cd_home, cd_home, cd_back};
    char rtn = '3';

    for (int i = 0; 3 > i; ++i)
        if (0 == my_strcmp(dir, path[i])) {
            rtn = cd_path[i](shell, command);
            return (rtn);
        }
    return (rtn);
}

static void print_flags(shell_t *shell, char *flags)
{
    char *begin = "~";
    char *rest = NULL;

    if ('\0' == flags[0])
        return;
    for (int i = 0; flags[i]; ++i)
        if ('l' == flags[i])
            begin = NULL;
    rest = (get_envvar(shell->env, "PWD") + 4);
    for (int i = 0; flags[i]; ++i)
        if ('v' == flags[i])
            my_putstr("0\t");
    if (NULL != begin) {
        my_putstr(begin);
        my_putstr(rest + 11);
        my_putchar('\n');
        return;
    }
    my_putstr(rest);
    my_putchar('\n');
}

static char move_to_a_directory(shell_t *shell, command_t *command,
    char *flags, char *dir)
{
    char rtn = '0';

    rtn = special_cd(shell, command, dir);
    if ('3' != rtn) {
        print_flags(shell, flags);
        return (rtn);
    }
    if ('1' == my_chdir(dir))
        return ('0');
    if ('1' == update_oldpwd_and_pwd(shell, command))
        return ('1');
    print_flags(shell, flags);
    return ('0');
}

char my_cd(shell_t *shell, command_t *command)
{
    char *dir = NULL;
    char *flags = NULL;
    char rtn = '0';

    if (1 == command->nb_arg) {
        if ('1' == cd_home(shell, command))
            return ('1');
        return ('0');
    }
    dir = get_directory(command);
    flags = get_flags(command);
    if ('1' == check_dir_and_flags(command, dir, flags))
        return ('0');
    if (NULL == dir) {
        rtn = move_to_a_directory(shell, command, flags, "~");
        return (rtn);
    }
    rtn = move_to_a_directory(shell, command, flags, dir);
    free(flags);
    return (rtn);
}
