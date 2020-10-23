/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** Return 1 if the string contains only alphabetical characters
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            j += 1;
        if (str[i] >= 'A' && str[i] <= 'Z')
            j += 1;
        i += 1;
    }
    if (j == i)
        return (1);
    return (0);
}
