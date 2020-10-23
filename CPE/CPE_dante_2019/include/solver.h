/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** solver.h
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct tree_list_t {
    int pos;
    struct tree_list_t *next;
} tree_list_t;

typedef struct data_t {
    int line;
    int size;
    int ways;
    char *maze;
    int *solved;
    int *check;
    tree_list_t *tree;
} data_t;

void free_struct(data_t *data);

//? Check ways
tree_list_t *maze_check(data_t *data, tree_list_t *tree);
int *up_check(data_t *data, int i, int pos, int *pos_i);
int *down_check(data_t *data, int i, int pos, int *pos_i);
int *left_check(data_t *data, int i, int pos, int *pos_i);
int *right_check(data_t *data, int i, int pos, int *pos_i);

//? Solver
tree_list_t *tree_create(data_t *data);

//? Setup
data_t *fill_struct(char *file);
void maze_print(tree_list_t *tree, char *maze);
data_t *read_file(data_t *data, char *file);
int line_len(char *str);

#endif /* SOLVER_H_ */