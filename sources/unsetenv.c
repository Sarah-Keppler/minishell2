/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** Remove an EnvVar.
*/

#include <stddef.h>
#include <stdlib.h>
#include "proto.h"

static char **create_a_smaller_env(char **env, char *name)
{
    int i = -1;
    int index = -1;
    char **new = NULL;

    while (env[++i]);
    new = malloc(sizeof(char *) * i);
    if (NULL == new)
        return (NULL);
    i = 0;
    index = get_envvar_index(env, name);
    for (int y = 0; env[y]; ++y)
        if (index != y) {
            new[i] = env[y];
            ++i;
        }
    free(env[index]);
    free(env);
    return (new);
}

char my_unsetenv(shell_t *shell, command_t *command)
{
    char *name = NULL;

    for (int i = 1; command->args[i]; ++i) {
        name = command->args[i];
        if (NULL == get_envvar(shell->env, name))
            return ('0');
        shell->env = create_a_smaller_env(shell->env, name);
        if (NULL == shell->env)
            return ('1');
    }
    return ('0');
}
