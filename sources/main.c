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

static void free_command(command_t *command)
{
    free(command->line);
    for (int i = 0; command->args[i]; ++i)
        free(command->args[i]);
    free(command->args);
    free(command);
}

static void print_command_not_found(command_t *command)
{
    my_puterror(command->args[0]);
    my_puterror(": Command not found.\n");
}

static char execute_a_command(shell_t *shell, int *exit)
{
    return ('0');
    char (*execute[3])(shell_t *) = {local_command,
        term_command, path_command};
    char rtn = '0';

    for (int i = 0; 3 > i; ++i) {
        rtn = execute[i](shell);
        if ('3' != rtn)
            break;
    }
    if (0 == my_strcmp("exit", shell->command->args[0])) {
        *exit = 0;
        return ('0');
    }
    if ('3' == rtn)
        print_command_not_found(shell->command);
    return ('0');
}

static char run(char **envp)
{
    shell_t *shell = init_shell(envp);
    int exit = 1;

    if (NULL == shell)
        return ('1');
    while (exit) {
        print_prompt();
        shell->command = init_command();
        if (NULL == shell->command)
            return ('1');
        my_putstr(shell->command->line);
        if ('3' == execute_a_command(shell, &exit))
            return ('1');
        free_command(shell->command);
    }
    if (isatty(0))
        my_putstr("exit\n");
    return ('0');
}

int main(int ac, char **av, char **envp)
{
    if ('1' == run(envp))
        return (84);
    return (0);
    my_put_nbr(ac);
    my_putstr(av[0]);
}
