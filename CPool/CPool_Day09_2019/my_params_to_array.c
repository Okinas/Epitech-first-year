/*
** EPITECH PROJECT, 2019
** my_params_to_array
** File description:
** Function that stores the program's parameters into an array
*/

#include "include/my.h"
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    int index = 0;
    struct info_param *out = malloc(sizeof(struct info_param) * (ac + 1));

    if (out == NULL)
        return (NULL);
    while (index < ac) {
        out[index].length = my_strlen(av[index]);
        out[index].str = av[index];
        out[index].copy = my_strdup(av[index]);
        out[index].word_array = my_str_to_word_array(av[index]);
        index += 1;
    }
    out[index].str = 0;
    return (out);
}
