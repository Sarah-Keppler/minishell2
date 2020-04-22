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
#include "proto.h"

static void pinpoint_the_signal(int status)
{
    char *sig_output[32] = {"","Rupture\n", "Interruption Keyboard\n",
        "Stop (core dump)\n", "Illegal Instruction (core dump)\n", "",
        "Anormal stop (core dump)\n", "",
        "Error floating number (core dump)\n", "Kill\n", "User signals\n",
        "Segmentation fault (core dump)\n", "User signals\n",
        "Error pipeline (core dump)\n", "Alarm signal\n", "Finished\n",
        "User signals\n", "User signals\n", "Children stopped\n",
        "Stop immediately\n", "Children stopped\n", "Input terminal\n",
        "Output terminal\n", "", "Stop process (Ctrl Z)\n",
        "Stop immediately\n", "Input terminal\n", "Output terminal\n", "",
        "", "User signals\n", "User signals\n"};
    int exit_stat = 0;

    if (WIFEXITED(status))
        exit_stat = WEXITSTATUS(status);
    if (WIFSIGNALED(status))
        exit_stat = WTERMSIG(status);
    if (WIFSTOPPED(status))
        exit_stat = WSTOPSIG(status);
    my_putstr(sig_output[exit_stat]);
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

static void execute_children(shell_t *shell, pid_t cpid, char *path)
{
    if (0 != cpid)
        return;
    execve(path, shell->command->args, shell->env);
}

char execute_a_binary(shell_t *shell, char *path)
{
    pid_t cpid = fork();

    if (-1 == cpid) {
        perror("cpid:");
        return ('1');
    }
    while (1) {
        execute_children(shell, cpid, path);
        execute_parent_part(cpid);
        if (0 != cpid)
            break;
    }
    return ('0');
}
