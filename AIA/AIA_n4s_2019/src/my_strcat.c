/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates 2 strings
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int count = 0;
    char *result;

    result = malloc(sizeof(*result) * (strlen(dest) + strlen(src) + 1));
    while (dest[i]) {
        result[i] = dest[i];
        i++;
    }
    while (src[count]) {
        result[i + count] = src[count];
        count++;
    }
    result[i + count] = '\0';
    return (result);
}
