/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_getnblines.c
*/

int my_getnblines(char *str, int index)
{
    int count = 1;

    while (str[index] != '\0') {
        if (str[index] == '\n' && str[index + 1] != '\0')
            count++;
        index++;
    }
    return (count);
}
