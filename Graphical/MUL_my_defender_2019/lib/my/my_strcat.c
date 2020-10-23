/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates 2 strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int count = 0;
    char *result;

    result = malloc(sizeof(*result) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i]) {
        result[i] = dest[i];
        i++;
    }
    while (src[count]) {
        result[i + count] = src[count];
        count++;
    }
    result[i + count] = '\0';
    free(dest);
    free(src);
    return (result);
}
