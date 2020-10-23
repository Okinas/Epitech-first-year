/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** Puts every letter of every word in lowercase
*/

char *my_strlowcase(char *str)
{
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] >= 'A' && str[index] <= 'Z')
            str[index] = str[index] - 32;
        index = index + 1; }
    return (0);
}
