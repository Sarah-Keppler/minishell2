/*
** EPITECH PROJECT, 2019
** local_command
** File description:
** Execute a local command.
*/

#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "proto.h"

static char *get_path_and_binary(command_t *command, int *index)
{
    char *path = NULL;
    int s = -1;

    for (int i = 0; command->line[i]; ++i)
        if ('/' == command->line[i])
            s = i;
    path = malloc(sizeof(char) * (my_strlen(command->args[0]) - s + 2));
    if (NULL == path)
        return (NULL);
    my_strcpy(path, command->args[0]);
    path[s + 1] = '\0';
    for (int i = 0; command->line[i]; ++i)
        if ('/' == command->line[i])
            *index = i;
    return (path);
}

static char check_file_type(char *file)
{
    struct stat sb;

    if (0 != stat(file, &sb))
        return ('3');
    switch (sb.st_mode & S_IFMT) {
    case S_IFDIR: return ('1');
    default : break;
    }
    return ('0');
}

static char check_directory(char *binary, char *path, char *src)
{
    DIR *dir = opendir(path);
    struct dirent *rd_file = NULL;
    char rtn = '0';

    if (NULL == dir)
        return ('1');
    rd_file = readdir(dir);
    if (NULL == rd_file)
        return ('1');
    while (NULL != rd_file) {
        if (0 != my_strcmp(rd_file->d_name, binary)) {
            rd_file = readdir(dir);
            continue;
        }
        rtn = check_file_type(src);
        if ('1' != rtn)
            return (rtn);
        rd_file = readdir(dir);
    }
    return ('1');
}

static char check_binary_exist(command_t *command)
{
    int index = -1;
    char *binary = NULL;
    char *path = get_path_and_binary(command, &index);
    char rtn = '0';
    
    if (NULL == path)
        return ('1');
    binary = command->args[0] + index + 1;
    rtn = check_directory(binary, path, command->args[0]);
    if ('1' == rtn)
        return ('3');
    if ('3' == rtn)
        return ('1');
    return (rtn);
}

char local_command(shell_t *shell)
{
    char *line = shell->command->line;
    char rtn = '0';

    if ('.' != line[0] && '/' != line[1])
        return ('3');
    rtn = check_binary_exist(shell->command);
    if ('0' != rtn)
        return (rtn);
    if ('1' == execute_a_binary(shell, shell->command->args[0]))
        return ('1');
    return ('0');
}
