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

static char create_new_pwd(shell_t *shell)
{
    char cwd[PATH_MAX];

    getcwd(cwd, PATH_MAX);
    if (NULL == cwd)
        return ('1');
    if ('1' == my_setenv(shell, "PWD", cwd))
        return ('1');
    return ('0');
}

static char update_oldpwd(shell_t *shell)
{
    char *pwd = get_envvar(shell->env, "PWD");
    char *value = malloc(sizeof(char) * (my_strlen(pwd) - 3));

    if (NULL == value)
        return ('1');
    my_strcpy(value, pwd + 4);
    if ('1' == my_setenv(shell, "OLDPWD", value))
        return ('1');
    free(value);
    return ('0');
}

static char update_pwd(shell_t *shell)
{
    char value[PATH_MAX];

    getcwd(value, PATH_MAX);
    if (NULL == value)
        return ('1');
    if ('1' == my_setenv(shell, "PWD", value))
        return ('1');
    return ('0');
}

//If NULL, modify in shell

char update_oldpwd_and_pwd(shell_t *shell)
{
    char **env = shell->env;
    char *value = get_envvar(env, "PWD");

    if (NULL == value) {
        if ('1' == create_new_pwd(shell))
            return ('1');
    }
    if (NULL != get_envvar(env, "OLDPWD"))
        if ('1' == update_oldpwd(shell))
            return ('1');
    if ('1' == update_pwd(shell))
        return ('1');
    return ('0');
}
