/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** maze_utils.c
*/

#include "generator.h"

char **maze_alloc(gen_t *gen)
{
    int i = 0;
    int max_y = gen->y + (gen->y - 1);
    int max_x = gen->x + (gen->x - 1);
    char **maze = malloc(sizeof(char *) * (max_y + 1) + 1);

    if (gen->x == 0 || gen->y == 0)
        return (NULL);
    while (i < max_y) {
        maze[i] = malloc(sizeof(char) * (max_x + 1) + 2);
        if (maze[i] == NULL)
            return (NULL);
        i += 1;
    }
    maze[i] = NULL;
    return (maze);
}

char **maze_fill(char **maze, gen_t *gen)
{
    int i = 0;
    int j = 0;

    while (i < gen->y + (gen->y - 1)) {
        j = 0;
        while (j < gen->x + (gen->x + 1)) {
            if (j % 2 == 0 && i % 2 == 0)
                maze[i][j] = '0';
            else if ((j % 2 != 0 && i % 2 == 0) || i % 2 != 0)
                maze[i][j] = '1';
            j += 1;
        }
        maze[i][j] = '\0';
        i += 1;
    }
    return (maze);
}

char **maze_final(char **maze, gen_t *gen)
{
    int i = 0;
    int j = 0;

    while (i < gen->y - 1)
        i += 1;
    while (j < gen->x - 1)
        j += 1;
    if (maze[i][j - 1] == '1' && maze[i - 1][j] == '1')
        maze[i][j - 1] = '0';
    return (maze);
}

void maze_print(char **maze, gen_t *gen)
{
    int not_printable = 0;

    for (int i = 0; i < gen->y; i += 1) {
        for (int j = 0; j < gen->x; j += 1) {
            if (i == gen->y - 1 && j == gen->x - 1 && maze[i][j] == '1') {
                printf("*");
                not_printable = 1;
            }
            if (maze[i][j] == '0')
                printf("*");
            if (maze[i][j] == '1' && not_printable != 1)
                printf("X");
        }
        if (i != gen->y - 1)
            printf("\n");
    }
}