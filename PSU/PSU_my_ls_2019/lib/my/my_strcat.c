/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Function that concatenates two strings
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int count = 0;
    char *res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[i]) {
        res[i] = dest[i];
        i += 1;
    }
    while (src[count]) {
        res[i + count] = src[count];
        count += 1;
    }
    res[i + count] = '\0';
    return (res);
}
