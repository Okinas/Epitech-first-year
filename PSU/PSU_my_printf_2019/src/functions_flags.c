/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** functions_flags.c
*/

#include <stdio.h>
#include "function.h"

void string_function(char *flags, int index, char *over, va_list ap)
{
    if (over == NULL || flags[index] != 's')
        return;
    my_putstr(va_arg(ap, char *));
}

void char_function(char *flags, int index, char *over, va_list ap)
{
    char cast = va_arg(ap, int);
    int precision = my_getnbr(over);

    if (over == NULL || flags[index] != 'c')
        return;
    while (precision > 0) {
        my_putchar(' ');
        precision -= 1;
    }
    my_putchar(cast);
}

void binary_function(char *flags, int index, char *over, va_list ap)
{
    unsigned long int cast = 0;

    if (over == NULL || flags[index] != 'b')
        return;
    cast = length_modifier_u(flags, cast, ap);
    convert_base_u(signs(flags, spaces(cast, 0, over)), "01");
    spaces(cast, 1, over);
}

void hexa_function(char *f, int index, char *over, va_list ap)
{
    unsigned long int cast = 0;

    if (over == NULL || (f[index] != 'x' && f[index] != 'X'))
        return;
    cast = length_modifier_u(f, cast, ap);
    if (over[0] == '#') {
        if (cast != 0) {
            if (f[index] == 'x')
                my_putstr("0x");
            else
                my_putstr("0X");
        } if (f[index] == 'x')
            my_putnbr_u(cast, "0123456789abcdef");
        if (f[index] == 'X')
            my_putnbr_u(cast, "0123456789ABCDEF");
        return;
    } if (f[index] == 'x')
        convert_base_u(signs(f, spaces(cast, 0, over)), "0123456789abcdef");
    if (f[index] == 'X')
        convert_base_u(signs(f, spaces(cast, 0, over)), "0123456789ABCDEF");
    spaces(cast, 1, over);
}

void int_function(char *flags, int index, char *over, va_list ap)
{
    long int cast = 0;

    if (over == NULL || (flags[index] != 'd' && flags[index] != 'i'))
        return;
    cast = length_modifier(flags, cast, ap);
    convert_base(signs(flags, spaces(cast, 0, over)), "0123456789");
    spaces(cast, 1, over);
}