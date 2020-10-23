/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** int_to_str.c
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

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