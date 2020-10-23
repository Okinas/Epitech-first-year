/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Task05
*/

int length_strstr(char const *to_find)
{
    int i = 0;

    while (to_find[i])
        i += 1;
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int a = 0;
    int b = 0;
    int c = length_strstr(to_find);

    while (str[a]) {
        while (to_find[b] && str[a] && str[a + b] == to_find[b]) {
            b += 1; }
        if (b == c)
            return (&(str[a]));
        a += 1;
        b = 0;
    }
    return (0);
}
