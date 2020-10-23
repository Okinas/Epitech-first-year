/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverse a string
*/

static void swap(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

static int length(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int length_end = length(str) - 1;

    while (i < length_end) {
        swap(&str[i], &str[length_end]);
        i += 1;
        length_end -= 1;
    }
    return (str);
}
