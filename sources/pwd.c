/*
** EPITECH PROJECT, 2019
** pwd
** File description:
** Update the pwd while moving from directories to directories.
*/

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

static char create_new_pwd(shell_t *shell, command_t *command)
{
    char cwd[PATH_MAX];

    getcwd(cwd, PATH_MAX);
    if (NULL == cwd)
        return ('1');
    if ('1' == my_setenv(shell, command, "PWD", cwd))
        return ('1');
    return ('0');
}

static char update_oldpwd(shell_t *shell, command_t *command)
{
    char *pwd = get_envvar(shell->env, "PWD");
    char *oldpwd = get_envvar(shell->env, "OLDPWD");

    if (NULL  == oldpwd) {
        shell->oldpwd = pwd + 4;
        return ('0');
    }
    if ('1' == my_setenv(shell, command, "OLDPWD", pwd + 4))
        return ('1');
    return ('0');
}

static char update_pwd(shell_t *shell, command_t *command)
{
    char value[PATH_MAX];

    getcwd(value, PATH_MAX);
    if (NULL == value)
        return ('1');
    if ('1' == my_setenv(shell, command, "PWD", value))
        return ('1');
    return ('0');
}

char update_oldpwd_and_pwd(shell_t *shell, command_t *command)
{
    char **env = shell->env;
    char *value = get_envvar(env, "PWD");

    if (NULL == value) {
        if ('1' == create_new_pwd(shell, command))
            return ('1');
    }
    if ('1' == update_oldpwd(shell, command))
        return ('1');
    if ('1' == update_pwd(shell, command))
        return ('1');
    return ('0');
}
