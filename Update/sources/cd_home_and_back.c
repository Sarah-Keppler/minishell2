/*
** EPITECH PROJECT, 2019
** cd_home_and_back
** File description:
** Move to home or at the last directory.
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "proto.h"

char cd_home(shell_t *shell, command_t *command)
{
    char *home = get_envvar(shell->env, "HOME");
    char *value = NULL;
    int cd = -1;

    if (NULL == home) {
        my_puterror("cd: No home directory.\n");
        return ('0');
    }
    value = malloc(sizeof(char) * (my_strlen(home) - 4));
    if (NULL == value)
        return ('1');
    my_strcpy(value, home + 5);
    cd = chdir(value);
    if (-1 == cd || '1' == update_oldpwd_and_pwd(shell, command))
        return ('1');
    free(value);
    return ('0');
}

char cd_back(shell_t *shell, command_t *command)
{
    char *value = get_envvar(shell->env, "OLDPWD");
    int cd = -1;

    if (NULL != value)
        value = value + 7;
    else
        value = shell->oldpwd;
    cd = chdir(value);
    if (-1 == cd || '1' == update_oldpwd_and_pwd(shell, command))
        return ('1');
    return ('0');
}
