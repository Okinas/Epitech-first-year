/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** Task14
*/

int my_islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_str_islower(char const *str)
{
    int i = 0;
    int	value;

    while (str[i] != '\0')
    {
        value = my_islower(str[i]);
        if (value == 0)
            return (0);
        i += 1;
    }
    return (1);
}
