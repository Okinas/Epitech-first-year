/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** nbr.c
*/

#include <stddef.h>

int my_getnbr(char const *str)
{
    int i = 0;
    long int nb = 0;
    int sign = 1;

    while (str[i] != '\0') {
        if ((str[i] == '-' && sign == -1 && nb == 0) ||
        (str[i] == '+' && nb == 0))
            sign = 1;
        else if (str[i] == '-' && nb == 0)
            sign = -1;
        if ((str[i] < '0' || str[i] > '9') && nb > 0)
            break;
        else if ((str[i] < '0' || str[i] > '9') && nb == 0) {
            i += 1;
            continue;
        } nb += str[i] - 48;
        nb *= 10;
        i += 1;
    }
    nb /= 10;
    return (nb * sign);
}
