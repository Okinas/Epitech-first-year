/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Function allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    str = my_strcpy(str, src);
    return (str);
}
