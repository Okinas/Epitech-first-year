/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Task07
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (1);
    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] - s2[i] < 0)
            return (s1[i] - s2[i]);
        if (s1[i] - s2[i] > 0)
            return (s1[i] - s2[i]);
        i += 1;
    }
    if (s1[i] == '\0')
        return (s1[i] - s2[i]);
    else
        return (0);
}
