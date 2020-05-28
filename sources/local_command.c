/*
** EPITECH PROJECT, 2019
** local_command
** File description:
** Execute a local command.
*/

#include <unistd.h>
#include "proto.h"

static char check_access(command_t *command)
{
    if (-1 == access(command->args[0], R_OK)) {
        my_puterror(command->args[0]);
        my_puterror(": Permission denied.\n");
        return ('1');
    }
    if (-1 == access(command->args[0], X_OK)) {
        my_puterror(command->args[0]);
        my_puterror(": Permission denied.\n");
        return ('1');
    }
    return ('0');
}

static char check_command(command_t *command)
{
    if (-1 == access(command->args[0], F_OK))
        return ('1');
    if ('1' == check_access(command))
        return ('1');
    return ('0');
}

char local_command(shell_t *shell, command_t *command)
{
    char *line = command->line;

    if ('/' != line[0] && '/' != line[1])
        return ('3');
    if ('1' == check_command(command))
        return ('3');
    if ('1' == execute_a_binary(shell, command, command->args[0]))
        return ('1');
    return ('0');
}
