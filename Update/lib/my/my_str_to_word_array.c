/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Put each work in an array, then return it.
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static void get_each_word(char **array, char *src, char c)
{
    int y = 0;
    int s = 0;

    for (int i = 0; src[i]; ++i) {
        if (c != src[i] && '\n' != src[i]) {
            array[y][s] = src[i];
            array[y][s + 1] = '\0';
            ++s;
        } else {
            s = 0;
            ++y;
        }
    }
}

static int my_count_words(char *src, char c)
{
    int nb = 0;

    for (int i = 0; src[i]; ++i)
        if (c == src[i])
            ++nb;
    ++nb;
    return (nb);
}

char **my_str_to_word_array(char *src, char c)
{
    int words = my_count_words(src, c);
    char **array = malloc(sizeof(char *) * (words + 1));

    if (NULL == array)
        return (NULL);
    for (int i = 0; words > i; ++i) {
        array[i] = malloc(sizeof(char) * (my_strlen(src) + 1));
        if (NULL == array[i])
            return (NULL);
    }
    get_each_word(array, src, c);
    array[words] = NULL;
    return (array);
}
