/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** my_convert.c
*/

#include "function.h"

void convert_base_u(unsigned long int nb, char *base)
{
    unsigned int size = my_strlen(base);

    if (nb >= size) {
        convert_base_u(nb / size, base);
        convert_base_u(nb % size, base);
    }
    else
        my_putchar(base[nb]);
}

void convert_base(long int nb, char *base)
{
    int size = my_strlen(base);

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= size) {
        convert_base(nb / size, base);
        convert_base(nb % size, base);
    }
    else
        my_putchar(base[nb]);
}