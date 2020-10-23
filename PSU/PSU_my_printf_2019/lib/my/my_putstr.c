/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display one by on the characters of a string.
*/

#include "function.h"

void my_putstr(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        my_putchar(str[index]);
        index += 1; }
}
