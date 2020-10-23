/*
** EPITECH PROJECT, 2019
** my_show_params_array
** File description:
** Function that Display the program's parameters into an array
*/

#include "include/my.h"
#include <stddef.h>

int my_show_param_array(struct info_param const *par)
{
    int index = 0;
    int temp = 0;

    while (par[index].str != 0) {
        my_putstr(par[index].copy);
        my_putchar('\n');
        my_put_nbr(par[index].length);
        my_putchar('\n');
        while (par[index].word_array[temp] != 0) {
            my_putstr(par[index].word_array[temp]);
            my_putchar('\n');
            temp += 1;
        }
        temp = 0;
        index += 1;
    }
    return (0);
}
