/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** array_str.c
*/

#include "shell.h"

int my_counter(char *str, char c)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        while (str[i] && (str[i] == c || str[i] == '\t'))
            i += 1;
        if (str[i])
            nb += 1;
        if (str[i] != '\0')
            i += 1;
    }
    return (nb);
}

int my_strlen_array(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c && str[i] != '\t')
        i += 1;
    return (i);
}

int skip_char(char *str, char c, int i)
{
    while (str[i] && (str[i] == c || str[i] == ' ' || str[i] == '\t'))
        i += 1;
    return (i);
}

char **str_to_double_array(char *str, char c)
{
    char **tab = malloc(sizeof(*tab) * (my_counter(str, c) + 1));
    int i = 0;
    int j = 0;
    int k = -1;

    if (tab == NULL)
        my_error("Malloc error");
    while (str[i]) {
        j = 0;
        i = skip_char(str, c, i);
        if ((tab[++k] = malloc(sizeof(**tab) *
        (my_strlen_array(&str[i], c) + 1))) == NULL)
            my_error("Malloc error");
        while (str[i] && str[i] != c && str[i] != ' ' && str[i] != '\t')
            tab[k][j++] = str[i++];
        tab[k][j] = '\0';
        i = skip_char(str, c, i);
    }
    tab[k + 1] = '\0';
    return (tab);
}