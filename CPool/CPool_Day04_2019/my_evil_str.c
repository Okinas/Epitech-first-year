/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** Swap each of the strings character two by two.
*/

int length(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1; }
    return (i);
}

char *my_evil_str(char *str)
{
    int a = 0;
    int b = length(str);
    int temp = 0;

    while (a < b)
    {
        str[a] = temp;
        str[b] = str[a];
        temp = str[b];
        b = b + 1;
        a = a + 1;
    }
    return (str);
}
