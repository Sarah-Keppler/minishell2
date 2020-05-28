/*
** EPITECH PROJECT, 2019
** path_command
** File description:
** Execute a path command.
*/

#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include "proto.h"

static char execute_binary(shell_t * shell, command_t *command, char *path,
    char *binary)
{
    int len = my_strlen(path) + my_strlen(binary) + 1;
    char *exec_path = malloc(sizeof(char) * (len + 1));

    if (NULL == exec_path)
        return ('1');
    my_strcpy(exec_path, path);
    my_strcat(exec_path, "/");
    my_strcat(exec_path, binary);
    if ('1' == execute_a_binary(shell, command, exec_path))
        return ('1');
    free(exec_path);
    return ('0');
}

static char check_path(char *binary, DIR *dir, struct dirent *rd_file)
{
    while (NULL != rd_file) {
        if (0 == my_strcmp(binary, rd_file->d_name))
            return ('0');
        rd_file = readdir(dir);
    }
    return ('1');
}

static char *find_binary(char **path, char *binary)
{
    DIR *dir = NULL;
    struct dirent *rd_file;

    for (int i = 0; path[i]; ++i) {
        dir = opendir(path[i]);
        if (NULL == dir)
            continue;
        rd_file = readdir(dir);
        if ('0' == check_path(binary, dir, rd_file))
            return (path[i]);
        rd_file = NULL;
        closedir(dir);
    }
    return (NULL);
}

char path_command(shell_t *shell, command_t *command)
{
    char *path = get_envvar(shell->env, "PATH");
    char **values = NULL;
    char *exec_path = NULL;

    values = my_str_to_word_array(path + 4, ':');
    if (NULL == values)
        return ('1');
    exec_path = find_binary(values, command->args[0]);
    if (NULL == exec_path)
        return ('3');
    if ('1' == execute_binary(shell, command, exec_path, command->args[0]))
        return ('1');
    return ('0');
}
