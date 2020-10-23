/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display for n digits.
*/

#include "my.h"

void my_putnbr_u(unsigned long int nb, char *base)
{
    unsigned long int size = my_strlen(base);

    if (nb >= size) {
        my_putnbr_u(nb / size, base);
        my_putnbr_u(nb % size, base);
    } else
        my_putchar(base[nb]);
}
