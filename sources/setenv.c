/*
** EPITECH PROJECT, 2019
** my_setenv
** File description:
** Add or change an EnvVar.
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

static char check_setenv_arguments(command_t *command, char *name)
{
    if (3 < command->nb_arg) {
        my_puterror("setenv: Too many arguments.\n");
        return ('1');
    }
    for (int i = 0; name[i]; ++i) {
        if (0 == i && !('A' <= name[i] && 'Z' >= name[i]) &&
            !('a' <= name[i] && 'z' >= name[i])) {
            my_puterror("setenv: Variable name must begin with a letter.\n");
            return ('1');
        }
        if (!('A' <= name[i] && 'Z' >= name[i]) &&
            !('a' <= name[i] && 'z' >= name[i]) &&
            !('0' <= name[i] && '9' >= name[i]) && '_' != name[i]) {
            my_puterror("setenv: Variable name must contain ");
            my_puterror("alphanumeric characters.\n");
            return ('1');
        }
    }
    return ('0');
}

static char **add_envvar(char **env, const char *name, const char *value)
{
    char **new = NULL;
    char *envvar = NULL;
    int i = -1;

    while(env[++i]);
    new = malloc(sizeof(char *) * (i + 2));
    if (NULL == new)
        return (NULL);
    for (int y = 0; env[y]; ++y)
        new[y] = env[y];
    envvar = malloc(sizeof(char) * (my_strlen(name) + my_strlen(value) + 2));
    if (NULL == envvar)
        return (NULL);
    my_strcpy(envvar, name);
    my_strcat(envvar, "=");
    my_strcat(envvar, value);
    new[i] = envvar;
    new[i + 1] = NULL;
    free(env);
    return (new);
}

char my_setenv(shell_t *shell, char *name, char *value)
{
    char rtn = '0';

    if ('1' == check_setenv_arguments(shell->command, name))
        return ('0');
    if (NULL == get_envvar(shell->env, name))
        shell->env = add_envvar(shell->env, name, value);
    else
        rtn = change_envvar(shell->env, name, value);
    if (NULL == shell->env || '1' == rtn)
        return ('1');
    return ('0');
}
