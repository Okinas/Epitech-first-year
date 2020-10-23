/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Function allocates memory and copies the string given as argument in it.
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int length = 0;
    char *str = NULL;
    int index = 0;

    if (src == NULL)
        return (NULL);
    length = my_strlen(src);
    str = malloc(length + 1);
    while (src[index]) {
        str[index] = src[index];
        index += 1;
    }
    str[index] = '\0';
    return (str);
}
