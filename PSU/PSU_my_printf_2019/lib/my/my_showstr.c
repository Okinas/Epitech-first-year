/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_showstr.c
*/

#include "function.h"

int my_showstr_invalid(char *str)
{
    int i = 0;
    int lenght = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32) {
            my_putchar(str[i]);
            lenght += 1;
        } else {
            my_convertbase_octa(str[i]);
            lenght += 4;
        } i += 1;
    }
    return (lenght);
}
