/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** spaces.c
*/

#include "function.h"

void my_spaces(int precision, int length, int order)
{
    int i = length;

    if (precision > 0 && order == 0) {
        while (i < precision) {
            my_putchar(' ');
            i += 1;
        }
    } else if (precision < 0 && order == 1) {
        precision = -precision;
        while (i < precision) {
            my_putchar(' ');
            i += 1;
        }
    }
}