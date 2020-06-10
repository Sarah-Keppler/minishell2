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

static char run(char **envp)
{
    shell_t *shell = init_shell(envp);
    int exit = 1;

    if (NULL == shell)
        return ('1');
    while (exit) {
        print_prompt();
        if ('0' != get_commands(shell))
            return ('0');
        execute_each_command(shell, &exit);
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
    run(envp);
    return (0);
    my_put_nbr(ac);
    my_putstr(av[0]);
}
