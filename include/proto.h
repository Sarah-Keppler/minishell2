/*
** EPITECH PROJECT, 2019
** proto.h
** File description:
** Protypes of all functions.
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "my.h"
#include "struct.h"

/*-----INIT-----*/
char **copy_env_original(char **);
shell_t *init_shell(char **);
command_t *init_command(void);

/*-----TERM FUNCTIONS-----*/
char my_setenv(shell_t *, char *, char *);
char my_unsetenv(shell_t *, char *);
char my_cd(shell_t *);
char cd_back(shell_t *);
char cd_home(shell_t *);

/*-----USEFUL FUNCTIONS-----*/
char change_envvar(char **, char *, char *);
int get_envvar_index(char **, char *);
char *get_envvar(char **, char *);
char update_oldpwd_and_pwd(shell_t *);

/*-----MAIN-----*/
void print_prompt(void);
char local_command(shell_t *);
char term_command(shell_t *);
char path_command(shell_t *);
char execute_a_binary(shell_t *, char *);

#endif /* PROTO_H_ */
