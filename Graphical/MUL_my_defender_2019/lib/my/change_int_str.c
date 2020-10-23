/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** change_int_str.c
*/

#include <stddef.h>
#include <stdlib.h>

int my_nblen(int nb)
{
    int i = 1;

    while (nb > 9) {
        nb /= 10;
        i += 1;
    }
    return (i);
}

char *change_int_str(int nb)
{
    char *str = NULL;
    int i = my_nblen(nb);

    str = malloc(sizeof(char) * (my_nblen(nb) + 1));
    str[i] = '\0';
    i -= 1;
    while (i >= 0) {
        str[i] = nb % 10 + 48;
        nb /= 10;
        i -= 1;
    }
    return (str);
}