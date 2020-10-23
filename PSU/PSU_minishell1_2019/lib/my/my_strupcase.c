/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** Puts every letter of every word in uppercase
*/

char *my_strupcase(char *str)
{
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] >= 'a' && str[index] <= 'z')
            str[index] = str[index] + 32;
        index = index + 1; }
    return (0);
}
