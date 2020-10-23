/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** solver.c
*/

#include "solver.h"

void find_the_way(data_t *data, int pos)
{
    int *pos_i = malloc(sizeof(int) * 5);
    int tmp = 0;

    if (pos_i == NULL)
        return;
    data->ways = 0;
    for (int i = 0; i != 5; i += 1)
        pos_i[i] = -1;
    pos_i = right_check(data, tmp, pos, pos_i);
    if (pos_i[tmp] != -1)
        tmp += 1;
    pos_i = down_check(data, tmp, pos, pos_i);
    if (pos_i[tmp] != -1)
        tmp += 1;
    pos_i = left_check(data, tmp, pos, pos_i);
    if (pos_i[tmp] != -1)
        tmp += 1;
    pos_i = up_check(data, tmp, pos, pos_i);
    data->solved = pos_i;
}

tree_list_t *find_tree(data_t *data, int pos)
{
    tree_list_t *tree = malloc(sizeof(tree_list_t));
    int *pos_i = NULL;
    int ways = 0;

    find_the_way(data, pos);
    ways = data->ways;
    if (data->ways == 0 || data->check[pos] == 1 || tree == NULL)
        return (NULL);
    pos_i = data->solved;
    tree->pos = pos;
    if (maze_check(data, tree) != NULL)
        return (tree);
    data->check[pos] = 1;
    for (int i = 0; ways-- != 0; i += 1) {
        if ((tree->next = find_tree(data, pos_i[i])) != NULL) {
            free(pos_i);
            return (tree);
        }
    } free(tree);
    return (NULL);
}

tree_list_t *tree_create(data_t *data)
{
    int ways = 0;
    int *pos_i = NULL;
    tree_list_t *tree = malloc(sizeof(tree_list_t));

    tree->pos = 0;
    data->check[0] = 1;
    find_the_way(data, tree->pos);
    pos_i = data->solved;
    ways = data->ways;
    for (int i = 0; ways-- != 0; i += 1) {
        if ((tree->next = find_tree(data, pos_i[i])) != NULL)
            return (tree);
    }
    return (NULL);
}