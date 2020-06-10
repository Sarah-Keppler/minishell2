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
char get_commands(shell_t *);

/*-----TERM FUNCTIONS-----*/
char my_setenv(shell_t *, command_t *, char *, char *);
char my_unsetenv(shell_t *, command_t *);
char my_cd(shell_t *, command_t *);
char *get_directory(command_t *);
char *get_flags(command_t *);
char check_dir_and_flags(command_t *, char *, char *);
char my_chdir(char *);
char cd_back(shell_t *, command_t *);
char cd_home(shell_t *, command_t *);

/*-----USEFUL FUNCTIONS-----*/
char change_envvar(char **, char *, char *);
int get_envvar_index(char **, char *);
char *get_envvar(char **, char *);
char update_oldpwd_and_pwd(shell_t *, command_t *);

/*-----MAIN-----*/
void print_prompt(void);
char execute_each_command(shell_t *, int *);
char local_command(shell_t *, command_t *);
char check_binary_exist(command_t *);
char term_command(shell_t *, command_t *);
char path_command(shell_t *, command_t *);
char execute_a_binary(shell_t *, command_t *, char *);
void print_error_command(command_t *);

/*-----FREE-----*/
void free_commands(command_t **);

#endif /* PROTO_H_ */
