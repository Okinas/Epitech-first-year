/*
** EPITECH PROJECT, 2019
** nb_cmp
** File description:
** NBCMP
*/

int my_strlen(char const *str);

int my_nbcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    while (s1[i] != '\0')
    {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
        i += 1;
    }
    return (0);
}
