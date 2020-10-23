/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display one by on the characters of a string.
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int index;

    index = 0;
    while (str[index] != '\0') {
        my_putchar(str[index]);
        index = index + 1; }
    return (0);
}
