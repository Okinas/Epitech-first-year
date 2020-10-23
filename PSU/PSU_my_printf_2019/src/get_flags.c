/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** get_flags.c
*/

#include "function.h"

int check_flags(char c)
{
    char *flags = "dicsupboxXS%#hlq+-0123456789";
    int i = 0;

    while (flags[i] != '\0') {
        if (flags[i] == c)
            return 1;
        i += 1;
    }
    return 0;
}

char *get_flags(int i, char *str)
{
    int counter = 0;
    char *result;

    result = malloc(sizeof(char) * 4);
    while (str[i] != '\0') {
        if (counter <= 1 && (str[i] == '%' || str[i] == ' ')) {
            result[counter] = str[i];
            counter += 1;
            i += 1;
            continue;
        }
        if (check_flags(str[i]) == 1 && counter > 0) {
            result[counter] = str[i];
            counter += 1;
        }
        else if (counter > 0)
            return result;
        i += 1;
    }
    return result;
}