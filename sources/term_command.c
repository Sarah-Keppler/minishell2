/*
** EPITECH PROJECT, 2019
** term_command
** File description:
** Execute a terminal command.
*/

#include <stddef.h>
#include "proto.h"

static void print_env(char **env)
{
    for (int i = 0; env[i]; ++i) {
	my_putstr(env[i]);
	my_putchar('\n');
    }
}

static char set_unsetenv(shell_t *shell)
{
    char *name = NULL;

    if (1 == shell->command->nb_arg) {
        my_puterror("unsetenv: Too few arguments.\n");
        return ('0');
    }
    name = shell->command->args[1];
    if ('1' == my_unsetenv(shell, name))
        return ('1');
    return ('0');
}

static char set_setenv(shell_t *shell)
{
    char *name = NULL;
    char *value = NULL;

    if (1 == shell->command->nb_arg) {
        print_env(shell->env);
        return ('0');
    }
    name = shell->command->args[1];
    if (2 == shell->command->nb_arg) {
        if ('1' == my_setenv(shell, name, ""))
            return ('1');
        return ('0');
    }
    value = shell->command->args[2];
    if ('1' == my_setenv(shell, name, value))
        return ('1');
    return ('0');
}

char term_command(shell_t *shell)
{
    char *command[3] = {"cd", "setenv", "unsetenv"};
    char(*term_func[3])(shell_t *) = {my_cd, set_setenv, set_unsetenv};
    char rtn = '0';

    if (0 == my_strcmp("env", shell->command->args[0])) {
        print_env(shell->env);
        return ('0');
    }
    for (int i = 0; 3 > i; ++i) {
        if (0 == my_strcmp(command[i], shell->command->args[0])) {
            rtn = term_func[i](shell);
            return (rtn);
        }
    }
    return ('3');
}
