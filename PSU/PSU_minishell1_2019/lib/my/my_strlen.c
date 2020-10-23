/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Counts and returns the number of characters found in a string.
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int index = 0;

    if (str == NULL)
        return (0);
    while (str[index] && str[index] != '\0')
        index += 1;
    return (index);
}
