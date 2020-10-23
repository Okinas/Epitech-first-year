/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** gen.h
*/

#ifndef GEN_H_
#define GEN_H_

#include "my.h"
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

typedef struct generator {
    int x;
    int y;
    int n;
    int w;
    bool perfect;
} gen_t;

int generator(gen_t *gen);
char **perfect_gen(gen_t *gen);
void broken_maze(char **maze, gen_t *gen);

//? Maze utils
char **maze_alloc(gen_t *gen);
char **maze_fill(char **maze, gen_t *gen);
char **maze_final(char **maze, gen_t *gen);
void maze_print(char **maze, gen_t *gen);

#endif /* GEN_H_ */