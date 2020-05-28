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

void error_envvar(shell_t *shell, command_t *command)
{
    my_setenv(shell, command, "error", "malloc");
}
