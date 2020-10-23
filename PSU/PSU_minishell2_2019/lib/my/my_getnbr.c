/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** nbr.c
*/

#include <stddef.h>

static int skip_letter(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i])
        i += 1;
    return (i - 1);
}

int my_getnbr(char const *str)
{
    int i = skip_letter(str);
    int tmp = 0;
    int pow = 1;

    while (i >= 0) {
        if (str[i] == '-') {
            tmp = -tmp;
        }
        else {
            tmp += (str[i] - '0') * pow;
            pow *= 10;
        }
        i -= 1;
    }
    return (tmp);
}