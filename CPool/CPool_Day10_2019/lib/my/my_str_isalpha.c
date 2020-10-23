/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** Return 1 if the string contains only alphabetical characters
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int index = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            index += 1;
        if (str[i] >= 'A' && str[i] <= 'Z')
            index += 1;
        i = i + 1; }
    if (index == i)
        return (1);
    return (0);
}
