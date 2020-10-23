/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display for n digits.
*/

#include "function.h"

char *converty(unsigned int nbr, int i, char *base)
{
    int size = my_strlen(base);
    char *final = malloc(sizeof(char) * 4);

    while (nbr > 0) {
        final[i] = base[nbr % size];
        i += 1;
        nbr /= size;
    }
    final[i] = '\0';
    return (final);
}

int my_convertbase_octaspe(unsigned int nbr)
{
    char *final = converty(nbr, 0, "01234567");

    my_putchar('0');
    my_revstr(final);
    my_putstr(final);
    return (my_strlen(final) + 1);
    free(final);
}