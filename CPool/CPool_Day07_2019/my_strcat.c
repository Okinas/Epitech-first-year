/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Function that concatenates two strings
*/

int length(char const *dest)
{
    int i = 0;

    while (dest[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int dest_length = length(dest);
    int index = 0;

    while (src[index] != '\0') {
        dest[dest_length + index] = src[index];
        index += 1;
    }
    dest[dest_length + index] = '\0';
    return (dest);
}
