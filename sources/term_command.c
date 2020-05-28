/*
** EPITECH PROJECT, 2019
** term_command
** File description:
** Execute a terminal command.
*/

#include <stddef.h>
#include "proto.h"

static void print_env(command_t *command, char **env)
{
    if (1 != command->nb_arg)
        return;
    for (int i = 0; env[i]; ++i) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

static char set_unsetenv(shell_t *shell, command_t *command)
{
    if (1 == command->nb_arg) {
        my_puterror("unsetenv: Too few arguments.\n");
        return ('0');
    }
    if ('1' == my_unsetenv(shell, command))
        return ('1');
    return ('0');
}

static char set_setenv(shell_t *shell, command_t *command)
{
    char *name = NULL;
    char *value = NULL;

    if (1 == command->nb_arg) {
        print_env(command, shell->env);
        return ('0');
    }
    name = command->args[1];
    if (2 == command->nb_arg) {
        if ('1' == my_setenv(shell, command, name, ""))
            return ('1');
        return ('0');
    }
    value = command->args[2];
    if ('1' == my_setenv(shell, command, name, value))
        return ('1');
    return ('0');
}

char term_command(shell_t *shell, command_t *command)
{
    char *commands[3] = {"cd", "setenv", "unsetenv"};
    char (*term_func[3])(shell_t *, command_t *) = {my_cd, set_setenv,
        set_unsetenv};
    char rtn = '0';

    if (0 == my_strcmp("env", command->args[0])) {
        print_env(command, shell->env);
        return ('0');
    }
    for (int i = 0; 3 > i; ++i) {
        if (0 == my_strcmp(commands[i], command->args[0])) {
            rtn = term_func[i](shell, command);
            return (rtn);
        }
    }
    return ('3');
}
