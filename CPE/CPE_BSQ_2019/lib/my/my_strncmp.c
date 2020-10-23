/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Reproduce the ncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && i < n) {
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
