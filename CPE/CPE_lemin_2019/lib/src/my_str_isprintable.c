/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** Task14
*/

int my_isprintable(char c)
{
    if (c >= 0 && c <= 31)
        return (0);
    return (1);
}

int my_str_isprintable(char const *str)
{
    int i = 0;
    int	value;

    while (str[i] != '\0')
    {
        value = my_isprintable(str[i]);
        if (value == 0)
            return (0);
        i += 1;
    }
    return (1);
}
