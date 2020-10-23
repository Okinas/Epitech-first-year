/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** flags_manager.c
*/

#include "function.h"

int apply_flags(char *flags, int index, char *over, va_list ap)
{
    if (dictionary[(int)flags[index]] != NULL) {
        dictionary[(int)flags[index]](flags, index, over, ap);
        return 1;
    }
    return 0;
}

unsigned long int spaces_u(unsigned long int nbr, int order, char *over)
{
    int over_length = my_strlen(over);
    int precision = my_getnbr(over);
    int nbr_length = int_len_u(nbr);

    if (over[over_length] == '+' || over[over_length] == '-')
        nbr_length += 1;
    if (precision != 0)
        my_spaces(precision, nbr_length, order);
    return nbr;
}

long int spaces(long int nbr, int order, char *over)
{
    int over_length = my_strlen(over);
    int precision = my_getnbr(over);
    int nbr_length = int_len(nbr);

    if ((over[over_length] == '+' || over[over_length] == '-') || nbr < 0)
        nbr_length += 1;
    if (precision != 0)
        my_spaces(precision, nbr_length, order);
    return nbr;
}

int flags_manager(char *f, va_list ap)
{
    int i = 0;
    int index = 1;
    int length = my_strlen(f);
    char *over = malloc(sizeof(char) * length - 1);

    if ((f[1] == '+' || f[1] == '-' || f[1] == '#' || f[1] == 'l'
    || f[1] == 'h' || f[1] == ' ' || f[1] == 'q'
    || (f[1] >= '0' && f[1] <= '9')) && length > 2) {
        index = length - 1;
        i = 1;
        while (i < index) {
            over[i - 1] = f[i];
            i += 1;
        }
    } if (length != 0) {
        if (over[0] == ' ')
            my_putchar(' ');
        if (apply_flags(f, index, over, ap) == 1)
            return 1;
    } free(over);
    return 0;
}