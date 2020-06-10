/*
** EPITECH PROJECT, 2019
** env
** File description:
** From the origal env: Print env, add/delete an EnvVar.
*/

#include <stdlib.h>
#include <stddef.h>
#include "proto.h"

char change_envvar(char **env, char *name, char *value)
{
    int index = get_envvar_index(env, name);
    char *envvar = NULL;

    free(env[index]);
    envvar = malloc(sizeof(char) * (my_strlen(name) + my_strlen(value) + 2));
    if (NULL == envvar)
        return ('1');
    my_strcpy(envvar, name);
    my_strcat(envvar, "=");
    my_strcat(envvar, value);
    env[index] = envvar;
    return ('0');
}

static int get_position_in_str(char *str, int c)
{
    int i = -1;
    int index = -1;

    while (str[++i])
        if (c == str[i]) {
            index = i;
            break;
        }
    return (index);
}

int get_envvar_index(char **env, char *envvar)
{
    int index = -1;
    int i = -1;
    int pos = -1;

    while (env[++i]) {
        index = get_position_in_str(env[i], '=');
        if (0 != my_strncmp(envvar, env[i], index))
            continue;
        if (index == my_strlen(envvar)) {
            pos = i;
            break;
        }
    }
    return (pos);
}

char *get_envvar(char **env, char *envvar)
{
    char *ptr = NULL;
    int index = -1;
    int i = -1;

    while (env[++i]) {
        index = get_position_in_str(env[i], '=');
        if (-1 == index)
            return (ptr);
        if (0 != my_strncmp(envvar, env[i], index))
            continue;
        if (index == my_strlen(envvar)) {
            ptr = env[i];
            break;
        }
    }
    return (ptr);
}

char **copy_env_original(char **envp)
{
    char **new = NULL;
    int i = -1;

    while (envp[++i]);
    new = malloc(sizeof(char *) * (i + 1));
    if (NULL == new)
        return (NULL);
    for (int y = 0; envp[y]; ++y) {
        new[y] = malloc(sizeof(char) * (my_strlen(envp[y]) + 1));
        if (NULL == new[y])
            return (NULL);
        my_strcpy(new[y], envp[y]);
    }
    new[i] = NULL;
    return (new);
}
