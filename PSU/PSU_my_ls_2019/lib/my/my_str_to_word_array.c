/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Splits a strings into words
*/

#include <unistd.h>
#include <stdlib.h>

int my_delim(char str, char *limit)
{
    int i = 0;

    while (limit[i]) {
        if (str == limit[i])
            return (-1);
        i += 1;
    }
    return (0);
}

int while_delim(char *str, int i, char *limit)
{
    if (my_delim(str[i], limit) == -1) {
        while (my_delim(str[i], limit))
            i += 1;
        i -= 1;
    }
    return (i);
}

int count_word(char *str, char *limit)
{
    int i = 0;
    int count = 1;

    while (str[i]) {
        i = while_delim(str, i, limit);
        count += 1;
        i += 1;
    }
    return (count);
}

int size(char *str, int i, char *limit)
{
    int length = 0;

    while (my_delim(str[i], limit) == 0 && str[i]) {
        length += 1;
        i += 1;
    }
    return (length);
}

char **my_str_to_word_array(char *str, char *limit)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int nb_word = count_word(str, limit) + 2;
    char **tab = malloc(sizeof(char *) * nb_word + 1);

    while (str[i]) {
        x = 0;
        while (my_delim(str[i], limit) == -1 && str[i])
            i += 1;
        tab[y] = malloc(sizeof(char) * size(str, i , limit) + 1);
        while (my_delim(str[i], limit) == 0 && str[i]) {
            tab[y][x] = str[i];
            i += 1;
            x += 1;
        } tab[y][x] = '\0';
        y += 1;
        while (my_delim(str[i], limit) == -1 && str[i])
            i += 1;
    } tab[y] = NULL;
    return (tab);
}
