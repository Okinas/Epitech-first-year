/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** check_move.c
*/

#include "solver.h"

tree_list_t *maze_check(data_t *data, tree_list_t *tree)
{
    if (data->maze[tree->pos + 1] == 0) {
        tree->next = NULL;
        return (tree);
    }
    return (NULL);
}

int *up_check(data_t *data, int i, int pos, int *pos_i)
{
    if (pos - data->line >= 0 && data->maze[pos - data->line] == '*') {
        data->ways += 1;
        pos_i[i] = pos - data->line;
    }
    return (pos_i);
}

int *down_check(data_t *data, int i, int pos, int *pos_i)
{
    if (pos + data->line < data->size && data->maze[pos + data->line] == '*') {
        data->ways += 1;
        pos_i[i] = pos + data->line;
    }
    return (pos_i);
}

int *left_check(data_t *data, int i, int pos, int *pos_i)
{
    if (pos - 1 >= 0 && data->maze[pos - 1] == '*') {
        data->ways += 1;
        pos_i[i] = pos - 1;
    }
    return (pos_i);
}

int *right_check(data_t *data, int i, int pos, int *pos_i)
{
    if (pos + 1 < data->size && data->maze[pos + 1] == '*') {
        data->ways += 1;
        pos_i[i] = pos + 1;
    }
    return (pos_i);
}