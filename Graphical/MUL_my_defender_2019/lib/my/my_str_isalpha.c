/*
** EPITECH PROJECT, 2019
** my_str_isalpha.c
** File description:
** Task12
*/

int my_isalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isalpha(char const *str)
{
    int i = 0;
    int value;

    while (str[i] != '\0')
    {
        value = my_isalpha(str[i]);
        if (value == 0)
            return (0);
        i += 1;
    }
    return (1);
}
