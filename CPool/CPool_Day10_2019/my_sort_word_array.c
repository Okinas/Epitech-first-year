/*
** EPITECH PROJECT, 2019
** my_sort_params
** File description:
** Display arguments on different lines.
*/

#include "my.h"
#include <unistd.h>

int swap(char **tab, int index)
{
    int temp = 0;

    if (index > 0 && tab[index][temp] < tab[index - 1][temp])
        return (1);
    else if (index > 0 && tab[index][temp] == tab[index - 1][temp]) {
        while (tab[index][temp] == tab[index - 1][temp])
            temp += 1;
        if (tab[index][temp] == tab[index - 1][temp])
            return (1);
        else
            return (0);
    }
    else
        return (0);
}

int my_sort_word_array(char **tab)
{
    int index = 0;
    char *temp = NULL;

    while (tab[index] != NULL)
    {
        if (swap(tab, index) == 1) {
            temp = my_strdup(tab[index - 1]);
            tab[index] = my_strdup(tab[index - 1]);
            tab[index - 1] = my_strdup(temp);
            index -= 2;
        }
        index += 1;
    }
    return (0);
}
