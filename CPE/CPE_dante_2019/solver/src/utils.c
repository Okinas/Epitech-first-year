/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** utils.c
*/

#include "solver.h"

void maze_print(tree_list_t *tree, char *maze)
{
    if (maze[0] == 'X' || maze[strlen(maze)] == 'X' || tree == NULL)
        printf("No solution found\n");
    else {
        for (; tree != NULL; tree = tree->next) {
            maze[tree->pos] = 'o';
        }
        printf("%s", maze);
    }
}

data_t *read_file(data_t *data, char *file)
{
    int fd = open(file, O_RDONLY);
    int size = 0;
    struct stat stat_t;

    if (fd == -1)
        return (NULL);
    stat(file, &stat_t);
    data->maze = malloc(sizeof(char) * (stat_t.st_size + 1));
    if (data->maze == NULL)
        return (NULL);
    size = read(fd, data->maze, stat_t.st_size);
    if (size <= 0)
        return (NULL);
    data->maze[size] = '\0';
    return (data);
}

int line_len(char *str)
{
    int	len = 0;

    while (str[len] != '\n' && str[len])
        len += 1;
    return (len);
}

static void tree_free(tree_list_t *tree)
{
    tree_list_t *tmp = tree;
    tree_list_t *next = tmp->next;

    while (next != NULL) {
        free(tmp);
        tmp = next;
        next = tmp->next;
    }
}

void free_struct(data_t *data)
{
    if (data->solved != NULL)
        free(data->solved);
    if (data->check != NULL)
        free(data->check);
    if (data->tree != NULL)
        tree_free(data->tree);
    free(data);
}