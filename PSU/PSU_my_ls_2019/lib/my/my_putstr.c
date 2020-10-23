/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display one by on the characters of a string.
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}
