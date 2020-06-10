/*
** EPITECH PROJECT, 2019
** init_shell
** File description:
** Init the shell structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include "proto.h"

static char *my_getline(void)
{
    char *buf = NULL;
    size_t n = 0;
    int rtn = getline(&buf, &n, stdin);

    if (-1 == rtn || EOF == rtn)
        return (NULL);
    while ('\n' == buf[0]) {
        print_prompt();
        buf = NULL;
        n = 0;
        rtn = getline(&buf, &n, stdin);
        if (-1 == rtn || EOF == rtn)
            return (NULL);
    }
    return (buf);
}

static char **get_user_commands(char *eof)
{
    char *buf = my_getline();
    char **commands = NULL;

    if (NULL == buf) {
        *eof = '0';
        return (NULL);
    }
    commands = my_str_to_word_array(buf, ';');
    if (NULL == commands)
        return (NULL);
    return (commands);
}

static command_t *init_command(char *command)
{
    command_t *new = malloc(sizeof(command_t));
    int i = 0;

    if (NULL == new)
        return (NULL);
    new->line = remove_space_and_tab(command);
    if (NULL == new->line)
        return (NULL);
    new->args = my_str_to_word_array(new->line, ' ');
    if (NULL == new->args)
        return (NULL);
    while (new->args[++i]);
    new->nb_arg = i;
    return (new);
}

char get_commands(shell_t *shell)
{
    char eof = '1';
    char **buf = get_user_commands(&eof);
    int nbr = -1;
    command_t **new = NULL;

    if (NULL == buf)
        return (('0' == eof) ? ('3') : ('1'));
    while (buf[++nbr]);
    new = malloc(sizeof(command_t *) * (nbr + 1));
    if (NULL == new)
        return ('1');
    for (int i = 0; buf[i]; ++i) {
        new[i] = init_command(buf[i]);
        if (NULL == new[i])
            return ('1');
    }
    new[nbr] = NULL;
    shell->commands = new;
    return ('0');
}
