/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** length_modifier.c
*/

#include "function.h"

unsigned long int short_length_u(char c, unsigned long int cast, va_list ap)
{
    unsigned char caster = 0;
    unsigned short int casty = 0;

    if (c == 'h') {
        caster = va_arg(ap, unsigned int);
        cast = caster;
        return cast;
    }
    casty = va_arg(ap, unsigned int);
    cast = casty;
    return cast;
}

unsigned long int length_modifier_u(char *flags,
unsigned long int cast, va_list ap)
{
    int i = 0;

    while (flags[i] != '\0') {
        if (flags[i] == 'h') {
            return (short_length_u(flags[i + 1], cast, ap));
        }
        else if (flags[i] == 'l' || flags[i] == 'q') {
            cast = va_arg(ap, unsigned long int);
            return cast;
        } i += 1;
    } cast = va_arg(ap, unsigned int);
    return cast;
}