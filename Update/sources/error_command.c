/*
** EPITECH PROJECT, 2019
** Main
** File description:
** FIrst Year Project: Rebuilt a terminal.
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include "proto.h"

static char check_if_directory(char *command)
{
    DIR *dir = opendir(command);

    if (NULL == dir)
        return ('1');
    return ('0');
}

static char check_file_and_directory(char *command)
{
    char path = '1';

    for (int i = 0; command[i]; ++i)
        if ('/' == command[i])
            path = '0';
    if ('1' == path)
        return ('1');
    if (-1 == access(command, F_OK))
        my_puterror(" : No such file or directory. (to check) \n");
    else if ('1' == check_if_directory(command))
        my_puterror(" : is a directory. (to check)\n");
    else
        my_puterror(" : is not a directory. (to check)\n");
    return ('0');
}

void print_error_command(command_t *command)
{
    my_puterror(command->args[0]);
    if ('1' == check_file_and_directory(command->args[0]))
        my_puterror(" : Command not found.\n");
}
