/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** Struct of the project's structs.
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct command_s {
    char *line;
    char **args;
    int nb_arg;
} command_t;

typedef struct shemm_s {
    command_t *command;
    char **env;
    char *oldpwd;
} shell_t;

#endif /* STRUCT_H_ */
