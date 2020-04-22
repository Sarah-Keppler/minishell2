/*
** EPITECH PROJECT, 2019
** init_shell
** File description:
** Init the shell structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

static char *get_user_command(void)
{
    char *buffer = NULL;
    size_t n = 0;
    int rtn = 0;

    rtn = getline(&buffer, &n, stdin);
    if (-1 == rtn || EOF == rtn)
        return (NULL);
    while ('\n' == buffer[0]) {
        print_prompt();
        buffer = NULL;
        n = 0;
        rtn = getline(&buffer, &n, stdin);
        if (-1 == rtn || EOF == rtn)
            return (NULL);
    }
    return (buffer);
}

static char set_up_command(command_t *command)
{
    command->line = get_user_command();
    if (NULL == command->line)
        return ('1');
    command->line = remove_space_and_tab(command->line);
    if (NULL == command->line)
        return ('1');
    command->args = my_str_to_word_array(command->line, ' ');
    if (NULL == command->args)
        return ('1');
    return ('0');
}

command_t *init_command(void)
{
    command_t *command = malloc(sizeof(command_t));
    int i = 0;

    if (NULL == command)
        return (NULL);
    if ('1' == set_up_command(command))
        return (NULL);
    while (command->args[++i]);
    command->nb_arg = i;
    return (command);
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
    if (NULL == new->oldpwd)
        return (NULL);
    return (new);
}
