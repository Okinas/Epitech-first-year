/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** signs.c
*/

#include "function.h"

unsigned long int signs_u(char *flags, unsigned long int nbr)
{
    int i = 0;
    int sign = 0;

    while (flags[i] != '\0') {
        if (sign == 0 && flags[i] == '+')
            sign = 1;
        if (flags[i] == '-')
            sign *= -1;
        else if (flags[i] == '+')
            sign *= 1;
        i += 1;
    }
    if (nbr > 0 && sign == 1)
        my_putchar('+');
    return nbr;
}

long int signs(char *flags, long int nbr)
{
    int i = 0;
    int sign = 0;

    while (flags[i] != '\0') {
        if (sign == 0 && flags[i] == '+')
            sign = 1;
        i += 1;
    }
    if (nbr >= 0 && sign == 1)
        my_putchar('+');
    return nbr;
}
