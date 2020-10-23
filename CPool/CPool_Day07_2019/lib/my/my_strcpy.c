/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Copy a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int index = 0;

    while (src[index] != '\0') {
        dest[index] = src[index];
        index = index + 1;
    }
    dest[index] = '\0';
    return (dest);
}
