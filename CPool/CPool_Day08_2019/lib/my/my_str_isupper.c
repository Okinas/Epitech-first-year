/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** Function return 1 if the string contains only upper characters
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    int index = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            index += 1;
        i = i + 1; }
    if (index == i)
        return (1);
    return (0);
}
