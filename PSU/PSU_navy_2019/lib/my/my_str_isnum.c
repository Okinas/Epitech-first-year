/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** Task13
*/

int my_isalphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isalphanum(char const *str)
{
    int i = 0;
    int	value;

    while (str[i] != '\0')
    {
        value = my_isalphanum(str[i]);
        if (value == 0)
            return (0);
        i += 1;
    }
    return (1);
}

int my_isnum(char c)
{
    if ((c >= '0' && c <= '9') || c == '-' || c == '\n')
        return (1);
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;
    int	value;

    while (str[i] != '\0')
    {
        value = my_isnum(str[i]);
        if (value == 0)
            return (0);
        i += 1;
    }
    return (1);
}
