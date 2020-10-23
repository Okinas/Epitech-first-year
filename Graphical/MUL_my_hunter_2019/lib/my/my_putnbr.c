/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display for n digits.
*/

#include "my.h"

void my_putnbr(int nb, char *base)
{
    int size = my_strlen(base);
    long nb1 = nb;

    if (nb1 < 0) {
        my_putchar('-');
        nb1 = -nb1; }
    if (nb1 >= size) {
        my_putnbr(nb1 / size, base);
        my_putnbr(nb1 % size, base);
    } else
        my_putchar(base[nb1]);
}
