/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** broken_maze.c
*/

#include "generator.h"

void broken_maze(char **maze, gen_t *gen)
{
    int x = 0;
    int y = 0;
    int walls_broken = (gen->x * gen->y) / 2;

    for (int i = 0; i < walls_broken; i += 1) {
        y = rand() % gen->y;
        x = rand() % gen->x;
        if (maze[y][x] == '1')
            maze[y][x] = '0';
    }
}