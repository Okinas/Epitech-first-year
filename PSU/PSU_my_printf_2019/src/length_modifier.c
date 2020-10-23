/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** length_modifier.c
*/

#include "function.h"

long int short_length(char c, long int cast, va_list ap)
{
    char caster = 0;
    short int casty = 0;

    if (c == 'h') {
        caster = va_arg(ap, int);
        cast = caster;
    }
    else {
        casty = va_arg(ap, int);
        cast = casty;
    }
    return cast;
}

long int length_modifier(char *flags, long int cast, va_list ap)
{
    int i = 0;

    while (flags[i] != '\0') {
        if (flags[i] == 'h') {
            return (short_length(flags[i + 1], cast, ap));
        }
        else if (flags[i] == 'l' || flags[i] == 'q') {
            cast = va_arg(ap, long int);
            return cast;
        } i += 1;
    } cast = va_arg(ap, int);
    return cast;
}