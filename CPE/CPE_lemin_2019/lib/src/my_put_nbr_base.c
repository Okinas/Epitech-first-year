/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** main.c
*/

#include "my.h"

void put_nbr_base_short_short(unsigned char nb, char *base)
{
    int max = my_strlen(base);

    if (nb >= max) {
        put_nbr_base_short_short(nb / max, base);
        put_nbr_base_short_short(nb % max, base);
    }
    else {
        my_putchar(base[nb]);
    }
}

void put_nbr_base_short(unsigned short int nb, char *base)
{
    int max = my_strlen(base);

    if (nb >= max) {
        put_nbr_base_short(nb / max, base);
        put_nbr_base_short(nb % max, base);
    }
    else {
        my_putchar(base[nb]);
    }
}

void put_nbr_base_long(unsigned long int nb, char *base)
{
    unsigned long int max = my_strlen(base);

    if (nb >= max) {
        put_nbr_base_long(nb / max, base);
        put_nbr_base_long(nb % max, base);
    }
    else {
        my_putchar(base[nb]);
    }
}

void put_nbr_base_int(unsigned int nb, char *base)
{
    unsigned int max = my_strlen(base);

    if (nb >= max) {
        put_nbr_base_int(nb / max, base);
        put_nbr_base_int(nb % max, base);
    }
    else {
        my_putchar(base[nb]);
    }
}

void my_put_nbr_base(unsigned long int nb, char *base, char *cast)
{
    if (my_strcmp(cast, "int") == 0)
        put_nbr_base_int(nb, base);
    if (my_strcmp(cast, "long") == 0)
        put_nbr_base_long(nb, base);
    if (my_strcmp(cast, "short") == 0)
        put_nbr_base_short(nb, base);
    if (my_strcmp(cast, "short short") == 0)
        put_nbr_base_short_short(nb, base);
}
