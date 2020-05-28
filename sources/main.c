/*
** EPITECH PROJECT, 2019
** Main
** File description:
** FIrst Year Project: Rebuilt a terminal.
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

static char execute_a_command(shell_t *shell, command_t *command, int *exit)
{
    char (*execute[3])(shell_t *, command_t *) = {local_command,
        term_command, path_command};
    char rtn = '0';

    for (int i = 0; 3 > i; ++i) {
        rtn = execute[i](shell, command);
        if ('3' != rtn)
            return (rtn);
    }
    if (0 == my_strcmp("exit", command->args[0])) {
        *exit = 0;
        return ('0');
    }
    if ('3' == rtn) {
        my_puterror(command->args[0]);
        my_puterror(": Command not found.\n");
    }
    return ('0');
}

static char check_filled_spaces(command_t *command)
{
    for (int i = 0; command->line[i]; ++i)
        if (' ' != command->line[i])
            return ('1');
    return ('0');
}

static char execute_each_command(shell_t *shell, int *exit)
{
    for (int i = 0; shell->commands[i]; ++i) {
        if ('0' == check_filled_spaces(shell->commands[i]))
            continue;
        if ('1' == execute_a_command(shell, shell->commands[i], exit))
            return ('1');
    }
    return ('0');
}

static char run(char **envp)
{
    shell_t *shell = init_shell(envp);
    int exit = 1;
    char rtn = '0';

    if (NULL == shell)
        return ('1');
    while (exit) {
        print_prompt();
        rtn = get_commands(shell);
        if ('0' != rtn)
            return (rtn);
        if ('1' == execute_each_command(shell, &exit))
            return ('1');
        free_commands(shell->commands);
    }
    if (isatty(0))
        my_putstr("exit\n");
    return ('0');
}

int main(int ac, char **av, char **envp)
{
    if (NULL == envp || NULL == envp[0])
        return (0);
    if ('1' == run(envp))
        return (84);
    return (0);
    my_put_nbr(ac);
    my_putstr(av[0]);
}
