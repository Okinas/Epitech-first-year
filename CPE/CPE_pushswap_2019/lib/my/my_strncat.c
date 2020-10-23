/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Function that concatenates two strings n characters
*/

int len(char *dest)
{
    int index = 0;

    while (dest[index] != '\0')
        index += 1;
    return (index);
}

char *my_strncat(char *dest, char const *src, int n)
{
    int index = 0;
    int dest_length = len(dest);

    while (index < n && src[index] != '\0') {
        index += 1;
        dest[dest_length + index] = src[index];
    }
    dest[dest_length + index] = '\0';
    return (dest);
}
