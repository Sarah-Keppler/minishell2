/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** Remove an EnvVar.
*/

#include <stddef.h>
#include <stdlib.h>
#include "proto.h"

static char **create_a_smaller_env(char **env)
{
    int i = -1;
    char **new = NULL;

    while(env[++i]);
    new = malloc(sizeof(char *) * i);
    if (NULL == new)
        return (NULL);
    i = 0;
    for (int y = 0; env[y]; ++y)
        if (NULL != env[y]) {
            new[i] = env[y];
            ++i;
        }
    free(env);
    return (new);
}

char my_unsetenv(shell_t *shell, char *name)
{
    int index = -1;

    if (2 != shell->command->nb_arg) {
        my_puterror("unsetenv: Too few arguments.\n");
        return ('0');
    }
    if (NULL == get_envvar(shell->env, name))
        return ('0');
    index = get_envvar_index(shell->env, name);
    free(shell->env[index]);
    shell->env = create_a_smaller_env(shell->env);
    if (NULL == shell->env)
        return ('1');
    return ('0');
}
