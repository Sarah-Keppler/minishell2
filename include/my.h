/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** My lib.
*/

#ifndef MY_H_
#define MY_H_

//Get_next_line:
#define READ_SIZE 50
char *get_next_line(int);

//my_math:
int my_pow(int, int);
int my_getnbr(char const *);

//my_rand:
char my_rand(int *, int, int);

//my_read:
char *read_a_file_with_stat(char *);
char *read_a_file(int, int);

//my_strcat:
void my_strcat(char *, char const *);
char *my_strcat_malloc(char *, char const *);

//my_strcpy:
void my_strcpy(char *, char const *);
void my_strncpy(char *, char const *, int);

//my_strcmp:
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);

//my_str_is:
char my_str_isnum(char const *);
char my_str_isnum_with_neg(char const *);
char my_str_isint_float(char const *);

//my_str_to_word_array:
char **my_str_to_word_array(char *, char);

//my_swap:
void my_swap_int(int *, int *);
void my_swap_char(char *, char *);

//my_write:
void my_putchar(char const);
void my_putstr(char const *);
void my_write(char const *);
void my_puterror(char const *);

//my_write_number:
void my_put_nbr(int);

//number:
int get_nb_of_time_char_appears(char *, char);
int get_nb_of_digits(int);

//str_manipulation:
int my_strlen(char const *);
void my_revstr(char *);
char *my_strstr(char *, char const *);
void my_int_to_str(int, char *);

//tab_and_spaces:
char *remove_space_and_tab(char const *);

#endif /* MY_H_ */
