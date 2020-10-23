/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** Function return 1 if the string contains only printable characters
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int index = 0;

    while (str[i] != '\0') {
        if (str[i] >= '!' && str[i] <= '~')
            index += 1;
        i = i + 1; }
    if (index == i)
        return (1);
    return (0);
}
