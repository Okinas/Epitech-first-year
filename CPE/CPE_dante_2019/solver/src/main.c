/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** main.c
*/

#include "solver.h"

int check_error(int ac)
{
    if (ac != 2)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    data_t *data = NULL;

    if (check_error(ac))
        return (84);
    data = fill_struct(av[1]);
    if (data == NULL)
        return (84);
    data->tree = tree_create(data);
    maze_print(data->tree, data->maze);
    free_struct(data);
    return (0);
}