/*
** EPITECH PROJECT, 2019
** solver
** File description:
** fill_struct.c
*/

#include "solver.h"

static int check_maze(data_t *data)
{
    int size = 0;

    for (int i = 0; data->maze[i]; i++) {
        if (data->maze[i] == '\n' || data->maze[i + 1] == '\0') {
            if (data->maze[i + 1] == '\0')
                size += 1;
            if (size != data->line - 1)
                return (1);
            size = -1;
        }
        size += 1;
    }
    return (0);
}

data_t *fill_struct(char *file)
{
    data_t *data = malloc(sizeof(data_t));

    data = read_file(data, file);
    if (data == NULL)
        return (NULL);
    data->line = line_len(data->maze) + 1;
    data->size = strlen(data->maze) + 1;
    if (check_maze(data))
        return (NULL);
    data->check = malloc(sizeof(int) * data->size);
    if (data->check == NULL)
        return (NULL);
    for (int i = 0; i < data->size; i++) {
        data->check[i] = 0;
    }
    return (data);
}