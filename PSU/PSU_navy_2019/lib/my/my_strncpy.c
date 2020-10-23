/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Task01
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (i != n)
    {
        dest[i] = src[i];
        i += 1;
    }
    return (dest);
}
