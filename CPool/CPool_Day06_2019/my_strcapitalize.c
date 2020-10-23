/*
** EPITECH PROJECT, 2019
** temp
** File description:
** Temp
*/

int my_strlen(char *str)
{
    int index = 0;

    while (str[index] != '\0')
        index += 1;
    return (index);
}

char *upper(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i - 1] < 48)
                str[i] -= 32; }
        i += 1;
    }
    return (str);
}

char *lower(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i - 1] > 48)
                str[i] += 32; }
        i += 1;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int index = my_strlen(str);

    upper(str);
    lower(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    str[index + 1] = '\0';
    return (str);
}
