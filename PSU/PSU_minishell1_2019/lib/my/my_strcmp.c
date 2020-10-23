/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Reproduce the cmp function
*/

int my_strcmp(char const *s1, char const *s2, int nb)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i += 1;
    }
    if (nb == 1)
        return (s1[i] == 61 && s2[i] == '\0');
    return ((s1[i] == s2[i] || s1[i] == ' ' || s1[i] == '\t') && s2[i] == '\0');
}
