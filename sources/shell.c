/*
** EPITECH PROJECT, 2019
** init_shell
** File description:
** Init the shell structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

static char set_shlvl(shell_t *shell)
{
    char *value = get_envvar(shell->env, "SHLVL");
    int shlvl = my_getnbr(value + 6) + 1;
    char *new = malloc(sizeof(char) * (shlvl + 1));
    command_t *tmp = malloc(sizeof(command_t));

    if (NULL == new || NULL == tmp)
        return ('1');
    tmp->nb_arg = 3;
    my_int_to_str(shlvl, new);
    if ('1' == my_setenv(shell, tmp, "SHLVL", new))
        return ('1');
    return ('0');
}

static char *get_oldpwd(shell_t *shell)
{
    char *home = NULL;
    char *new = NULL;

    home = get_envvar(shell->env, "HOME");
    if (NULL == home)
        return (NULL);
    new = malloc(sizeof(char) * (my_strlen(home + 4) + 1));
    if (NULL == new)
        return (NULL);
    my_strcpy(new, home + 4);
    return (new);
}

shell_t *init_shell(char **envp)
{
    shell_t *new = malloc(sizeof(shell_t));

    if (NULL == new)
        return (NULL);
    new->env = copy_env_original(envp);
    if (NULL == new->env)
        return (NULL);
    new->oldpwd = get_oldpwd(new);
    if (NULL == new->oldpwd || '1' == set_shlvl(new))
        return (NULL);
    return (new);
}
