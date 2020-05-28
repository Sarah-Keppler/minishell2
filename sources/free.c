/*
** EPITECH PROJECT, 2019
** Main
** File description:
** First Year Project: Rebuilt a terminal.
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

void free_commands(command_t **commands)
{
    for (int i = 0; commands[i]; ++i) {
        free(commands[i]->line);
        for (int y = 0; commands[i]->args[y]; ++y)
            free(commands[i]->args[y]);
        free(commands[i]);
    }
    free(commands);
}
