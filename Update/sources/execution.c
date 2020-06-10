/*
** EPITECH PROJECT, 2019
** execution
** File description:
** Execute the command.
*/

#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "proto.h"

static void pinpoint_the_signal_part2(int status, char **err, int *dump)
{
    if (WTERMSIG(status) == SIGFPE && (*dump = 1))
        *err = "Floating exception";
    if (WTERMSIG(status) == SIGABRT && (*dump = 1))
        *err = "Aborted";
    if (WTERMSIG(status) == SIGBUS && (*dump = 1))
        *err = "Bus error";
    return;
}

static void pinpoint_the_signal(int status)
{
    char *err = NULL;
    int dump = 0;

    if (WTERMSIG(status) == SIGSEGV && (dump = 1))
        err = "Segmentation fault";
    pinpoint_the_signal_part2(status, &err, &dump);
    if (NULL == err)
        return;
    my_puterror(err);
    if (dump && WCOREDUMP(status))
        my_puterror(" (core dumped)");
    my_puterror("\n");
}

static char execute_parent_part(pid_t cpid)
{
    pid_t w;
    int status = 0;

    if (0 == cpid)
        return ('0');
    do {
        w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
        if (w == -1) {
            perror("waitpid:");
            return ('1');
        }
        pinpoint_the_signal(status);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    return ('0');
}

static void execute_children(shell_t *shell, command_t *command, pid_t cpid,
    char *path)
{
    if (0 != cpid)
        return;
    execve(path, command->args, shell->env);
}

char execute_a_binary(shell_t *shell, command_t *command, char *path)
{
    pid_t cpid = fork();

    if (-1 == cpid) {
        perror("cpid:");
        return ('1');
    }
    while (1) {
        execute_children(shell, command, cpid, path);
        execute_parent_part(cpid);
        if (0 != cpid)
            break;
    }
    return ('0');
}
