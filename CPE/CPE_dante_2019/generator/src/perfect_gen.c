/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** perfect_gen.c
*/

#include "generator.h"

static void maze_walls(char **maze, int i, int j, gen_t *gen)
{
    if (i - 1 >= 0 && gen->n == 1 && gen->w == 0)
        maze[i - 1][j] = '0';
    if (j - 1 >= 0 && gen->n == 0 && gen->w == 1)
        maze[i][j - 1] = '0';
}

static void maze_corridor(char **maze, int random, int i, int j)
{
    random = rand() % 2;
    if (j - 1 >= 0 && random == 0)
        maze[i][j - 1] = '0';
    else if (i - 1 >= 0 && random == 1)
        maze[i - 1][j] = '0';
}

static void maze_nw(char **maze, int i, int j, gen_t *gen)
{
    if (i - 1 >= 0 && maze[i - 1][j] == '1')
        gen->n = 1;
    if (j - 1 >= 0 && maze[i][j - 1] == '1')
        gen->w = 1;
}

static void maze_perfect(char **maze, gen_t *gen)
{
    int random = 0;

    srand(getpid() * time(NULL));
    for (int i = 0; i < gen->y; i += 2) {
        gen->n = 0;
        gen->w = 0;
        for (int j = 0; j < gen->x; j += 2) {
            if (i == 0)
                maze[i][j] = '0';
            maze_nw(maze, i, j, gen);
            maze_walls(maze, i, j, gen);
            if (gen->n == 1 && gen->w == 1)
                maze_corridor(maze, random, i, j);
        }
    }
}

char **perfect_gen(gen_t *gen)
{
    char **maze = maze_alloc(gen);

    if (maze == NULL)
        return (NULL);
    maze = maze_fill(maze, gen);
    maze_perfect(maze, gen);
    return (maze);
}