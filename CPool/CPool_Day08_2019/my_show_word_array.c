/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** Function that displays the content of an array
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int index = 0;

    while (tab[index] != NULL)
    {
        my_putstr(tab[index]);
        my_putchar('\n');
        index += 1;
    }
    return (0);
}
