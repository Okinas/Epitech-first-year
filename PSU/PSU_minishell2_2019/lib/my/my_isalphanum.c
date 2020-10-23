/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_isalphanum.c
*/

#include <stddef.h>

int my_isalpha(const char c);

int my_isalphanum(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i]) {
        if ((str[i] >= '0' && str[i] <= '9') || my_isalpha(str[i]))
            i += 1;
        else
            return (0);
    }
    return (1);
}