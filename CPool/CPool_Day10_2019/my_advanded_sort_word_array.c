/*
** EPITECH PROJECT, 2019
** my_sort_params
** File description:
** Display arguments on different lines.
*/

#include "my.h"
#include <unistd.h>

int swapy(char **tab, int index, int(*cmp)(char const *, char const *))
{
    if (index > 0 && cmp(tab[index], tab[index - 1]) < 0)
        return (1);
    else
        return (0);
}

int my_advanced_sort_word_array(char **tab,
int(*cmp)(char const *, char const *))
{
    int index = 0;
    char *temp = NULL;

    while (tab[index] != NULL)
    {
        if (swapy(tab, index, cmp) == 1) {
            temp = my_strdup(tab[index]);
            tab[index] = my_strdup(tab[index - 1]);
            tab[index - 1] = my_strdup(temp);
            index -= 2;
        }
        index += 1;
    }
    return (0);
}
