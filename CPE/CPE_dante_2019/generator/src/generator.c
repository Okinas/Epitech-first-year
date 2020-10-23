/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** generator.c
*/

#include "generator.h"

int generator(gen_t *gen)
{
    char **maze = perfect_gen(gen);

    if (maze == NULL)
        return (84);
    if (gen->perfect == false)
        broken_maze(maze, gen);
    maze = maze_final(maze, gen);
    maze_print(maze, gen);
    return (0);
}