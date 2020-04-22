/*
** EPITECH PROJECT, 2019
** cd
** File description:
** Move from a directory to another.
*/

#include <stddef.h>
#include <unistd.h>
#include "proto.h"

static char special_cd(shell_t *shell)
{
    char *path[3] = {"~", "~/", "-"};
    char (*cd_path[3])(shell_t *) = {cd_home, cd_home, cd_back};
    char rtn = '3';

    for (int i = 0; 3 > i; ++i)
        if (0 == my_strcmp(shell->command->args[1], path[i])) {
            rtn = cd_path[i](shell);
            return (rtn);
        }
    return (rtn);
}

static char move_to_a_directory(shell_t *shell)
{
    char *directory = shell->command->args[1];
    int cd = -1;
    char rtn = '3';

    rtn = special_cd(shell);
    if ('3' != rtn)
        return (rtn);
    cd = chdir(directory);
    if (-1 == cd) {
        my_puterror(directory);
        my_puterror(": No such file or directory.\n");
        return ('0');
    }
    if ('1' == update_oldpwd_and_pwd(shell))
        return ('1');
    return ('0');
}

char my_cd(shell_t *shell)
{
    if (1 == shell->command->nb_arg) {
        if ('1' == cd_home(shell))
            return ('1');
        return ('0');
    }
    if (2 != shell->command->nb_arg) {
        my_puterror("cd: Too many arguments.\n");
        return ('0');
    }
    if ('1' == move_to_a_directory(shell))
        return ('1');
    return ('0');
}
