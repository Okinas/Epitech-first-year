/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** Return 1 if the string contains only digits
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int index = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            index += 1;
        i = i + 1; }
    if (index == i)
        return (1);
    return (0);
}
