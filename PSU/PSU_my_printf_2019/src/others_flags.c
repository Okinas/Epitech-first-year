/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** others_flags.c
*/

#include "function.h"

void adress_function(char *flags, int index, char *over, va_list ap)
{
    unsigned long int cast = va_arg(ap, unsigned long int);

    if (over == NULL || flags[index] != 'p')
        return;
    my_putstr("0x");
    convert_base_u(cast, "0123456789abcdef");
}

void unsigned_function(char *flags, int index, char *over, va_list ap)
{
    unsigned long int cast = 0;

    if (over == NULL || flags[index] != 'u')
        return;
    cast = length_modifier_u(flags, cast, ap);
    convert_base_u(signs_u(flags, spaces_u(cast, 0, over)), "0123456789");
    spaces_u(cast, 1, over);
}

void octal_function(char *flags, int index, char *over, va_list ap)
{
    unsigned long int cast = 0;

    if (over == NULL || flags[index] != 'o')
        return;
    cast = length_modifier_u(flags, cast, ap);
    if (over[0] == '#') {
        my_convertbase_octaspe(cast);
        return;
    }
    else {
        convert_base_u(signs(flags, spaces(cast, 0, over)), "01234567");
        spaces(cast, 1, over);
    }
}

void showstr_function(char *flags, int index, char *over, va_list ap)
{
    char *cast = va_arg(ap, char *);

    if (over == NULL || flags[index] != 'S')
        return;
    my_showstr_invalid(cast);
}

void percent_function(char *flags, int index, char *over, va_list ap)
{
    char cast = va_arg(ap, int);

    if (over == NULL || flags[index] != '%')
        return;
    cast = '%';
    my_putchar(cast);
}