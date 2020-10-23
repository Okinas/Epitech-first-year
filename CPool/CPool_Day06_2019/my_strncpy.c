/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Copy a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;

    while (index != n) {
        dest[index] = src[index];
        index = index + 1;
    }
    return (dest);
}
