/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** tool.c
*/

#include "my.h"
#include <stdbool.h>

int count_arg(char *str, char c)
{
    int i = 0;
    int nbr = 0;

    while (str[i]) {
        if ((str[i] == c || str [i + 1] == '\0') && str[i])
            ++nbr;
        ++i;
    }
    return (nbr);
}

static int count_space(char *str)
{
    int i = 0;

    while (*str) {
        if (*str == ' ')
            ++i;
        ++str;
    }
    return (i);
}

bool form_check(char *str)
{
    if (count_arg(str, ' ') < 3 || count_space(str) < 2)
        return (false);
    while (*str != ' ' && *str)
        ++str;
    ++str;
    while (*str != ' ') {
        if (*str < '0' || *str > '9')
            return (false);
        ++str;
    }
    ++str;
    while (*str != ' ' && *str) {
        if (*str < '0' || *str > '9')
            return (false);
        ++str;
    }
    return (true);
}

void print_msg(char *str, char c)
{
    int i = 0;

    while (str[i] && str[i] != c)
        my_putchar(str[i++]);
    my_putchar('\n');
}

void display(int nbr)
{
    my_putstr("#number_of_ants\n");
    my_put_nbr(nbr);
    my_putchar('\n');
    my_putstr("#rooms\n");
}