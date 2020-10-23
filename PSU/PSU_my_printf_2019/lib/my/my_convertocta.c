/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_convertocta.c
*/

#include "function.h"

void char_shift(char *final)
{
    int i = 3;

    while (my_strlen(final) != 3) {
        while (i != 0) {
            final[i] = final[i - 1];
            i -= 1;
        }
        i = 3;
        final[0] = '0';
    }
    my_putchar('\\');
    my_putstr(final);
}

char *convert(int nbr, int i, char *base)
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

void my_convertbase_octa(int nbr)
{
    char *final = convert(nbr, 0, "01234567");

    my_revstr(final);
    char_shift(final);
    free(final);
}