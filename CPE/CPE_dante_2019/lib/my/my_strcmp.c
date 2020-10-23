/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0')
    {
        if (s1[i] - s2[i] < 0)
            return (s1[i] - s2[i]);
        if (s1[i] - s2[i] > 0)
            return (s1[i] - s2[i]);
        i += 1;
    }
    return (s1[i] - s2[i]);
}
