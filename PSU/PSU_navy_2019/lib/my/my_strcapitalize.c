/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** Task10
*/

int is_cap(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (2);
    if (c >= '0' && c <= '9')
        return (0);
    return (3);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int value;
    int pre_value;

    while (str[i] != '\0') {
        if (i == 0)
            value = is_cap(str[i]);
        else {
            value = is_cap(str[i]);
            pre_value = is_cap(str[i - 1]);
        }
        if (i == 0 && value == 1)
            str[i] -= 32;
        if (value == 1 && pre_value == 3)
            str[i] -= 32;
        if (value == 2 && pre_value <= 2 && i != 0)
            str[i] += 32;
        i += 1; }
    return (str);
}
