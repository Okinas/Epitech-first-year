/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** my_printf.c
*/

#include "function.h"

void flags_dictionary(void)
{
    dictionary[(int)('i')] = int_function;
    dictionary[(int)('d')] = int_function;
    dictionary[(int)('c')] = char_function;
    dictionary[(int)('s')] = string_function;
    dictionary[(int)('x')] = hexa_function;
    dictionary[(int)('X')] = hexa_function;
    dictionary[(int)('b')] = binary_function;
    dictionary[(int)('p')] = adress_function;
    dictionary[(int)('u')] = unsigned_function;
    dictionary[(int)('o')] = octal_function;
    dictionary[(int)('S')] = showstr_function;
    dictionary[(int)('%')] = percent_function;
}

int parameters(int i, char *str, va_list ap)
{
    char *flags;

    flags = get_flags(i, str);
    if (flags_manager(flags, ap) == 1)
        i += my_strlen(flags) - 1;
    else
        my_putchar(str[i]);
    return i;
}

void my_printf(char *str, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, str);
    flags_dictionary();
    while (str[i] != '\0') {
        if (str[i] == '%')
            i = parameters(i, str, ap);
        else
            my_putchar(str[i]);
        i += 1;
    }
    va_end(ap);
}