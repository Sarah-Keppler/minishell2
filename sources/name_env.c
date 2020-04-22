/*
** EPITECH PROJECT, 2019
** name_env
** File description:
** Recup or create var name of / for the env.
*/

#include <stddef.h>
#include <stdlib.h>
#include "proto.h"

char *recup_the_var_name(envp_t *env)
{
    char *name = malloc(sizeof(char) * (my_strlen(env->elem) + 1));
    char fst = '0';

    if (NULL == name)
        return (NULL);
    my_strcpy(name, env->elem);
    for (int i = 0; name[i]; ++i)
        if ('=' == name[i] && '0' == fst) {
            name[i] = '\0';
            fst = '1';
        }
    return (name);
}

char *recup_the_var_value(envp_t *env, char *name)
{
    char *value = NULL;
    envp_t *tmp = env;
    char name_len = 0;

    while (0 != my_strcmp(tmp->name, name))
        tmp = tmp->next;
    name_len = my_strlen(tmp->name);
    value = malloc(sizeof(char) * (my_strlen(tmp->elem) - name_len + 1));
    if (NULL == value)
        return (NULL);
    my_strcpy(value, tmp->elem + name_len + 1);
    return (value);
}

char change_the_var_value(envp_t *env, char *name, char *new_value)
{
    int elem_len = my_strlen(new_value) + my_strlen(name) + 1;
    envp_t *tmp = env;

    while (0 != my_strcmp(tmp->name, name))
        tmp = tmp->next;
    free(tmp->elem);
    tmp->elem = malloc(sizeof(char) * (elem_len + 1));
    my_strcpy(tmp->elem, name);
    my_strcat(tmp->elem, "=");
    my_strcat(tmp->elem, new_value);
    return ('0');
}

char **linked_to_table(envp_t **env)
{
    envp_t *tmp = *env;
    int len = 0;
    char **array = NULL;

    while (NULL != tmp) {
        ++len;
        tmp = tmp->next;
    }
    array = malloc(sizeof(char *) * (len + 1));
    if (NULL == array)
        return (NULL);
    tmp = *env;
    for (int i = 0; NULL != tmp; ++i) {
        array[i] = malloc(sizeof(char) * (my_strlen(tmp->elem) + 1));
        if (NULL == array[i])
            return (NULL);
        my_strcpy(array[i], tmp->elem);
        tmp = tmp->next;
    }
    array[len] = NULL;
    return (array);
}
