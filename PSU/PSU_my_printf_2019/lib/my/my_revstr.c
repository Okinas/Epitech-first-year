/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverse a string
*/

void swapping(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

int leng(char const *str)
{
    int index = 0;

    while (str[index] != '\0')
        index = index + 1;
    return (index);
}

char *my_revstr(char *str)
{
    int index = 0;
    int length_end = leng(str) - 1;

    while (index < length_end) {
        swapping(&str[index], &str[length_end]);
        index = index + 1;
        length_end = length_end - 1;
    }
    return (str);
}
