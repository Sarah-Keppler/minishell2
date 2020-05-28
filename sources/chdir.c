/*
** EPITECH PROJECT, 2019
** cd
** File description:
** Move from a directory to another.
*/

#include <sys/stat.h>
#include <unistd.h>
#include "proto.h"

static char check_type(char *dir)
{
    struct stat sb;

    if (0 != stat(dir, &sb))
        return ('1');
    switch (sb.st_mode & S_IFMT) {
    case S_IFDIR: return ('0');
    default : break;
    }
    return ('1');
}

static char check_access(char *dir)
{
    if (-1 == access(dir, F_OK)) {
        my_puterror(dir);
        my_puterror(": No such file or directory.\n");
        return ('1');
    }
    if (-1 == access(dir, R_OK)) {
        my_puterror(dir);
        my_puterror(": Permission denied.\n");
        return ('1');
    }
    return ('0');
}

char my_chdir(char *dir)
{
    int cd = -1;

    if ('1' == check_access(dir))
        return ('1');
    if ('1' == check_type(dir)) {
        my_puterror(dir);
        my_puterror(": Not a directory.\n");
        return ('1');
    }
    cd = chdir(dir);
    if (-1 == cd)
        return ('1');
    return ('0');
}
