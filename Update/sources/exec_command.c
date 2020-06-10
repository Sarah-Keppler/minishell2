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
        if ('3' != rtn) {
            return (rtn);
        }
    }
    if (0 == my_strcmp("exit", command->args[0])) {
        *exit = 0;
        return ('0');
    }
    if ('3' == rtn)
        print_error_command(command);
    return ('0');
}

static char check_filled_spaces(command_t *command)
{
    for (int i = 0; command->line[i]; ++i)
        if (' ' != command->line[i])
            return ('1');
    return ('0');
}

char execute_each_command(shell_t *shell, int *exit)
{
    for (int i = 0; shell->commands[i]; ++i) {
        if ('0' == check_filled_spaces(shell->commands[i]))
            continue;
        if ('1' == execute_a_command(shell, shell->commands[i], exit))
            return ('1');
    }
    return ('0');
}
