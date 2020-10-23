/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Concatenates n characters of two strings
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, const char *src, int n)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (i < n && src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i += 1;
    }
    dest[dest_len + i] = '\0';
    return (dest);
}
