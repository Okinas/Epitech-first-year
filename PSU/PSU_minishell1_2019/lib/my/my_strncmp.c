/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Reproduce the ncmp function
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] != s2[i])
            return (1);
        i += 1;
    }
    return (0);
}
