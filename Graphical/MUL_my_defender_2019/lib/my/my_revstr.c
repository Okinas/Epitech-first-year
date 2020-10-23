/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Task03
*/

char *my_revstr(char *str)
{
    int i = 0;
    int end = 0;
    int x = 0;

    while (str[end] != '\0')
    {
        end += 1;
    }
    end -= 1;
    while (i < end)
    {
        x = str[i];
        str[i] = str[end];
        str[end] = x;
        i += 1;
        end -= 1;
    }
    return (str);
}
