/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban.h
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

typedef struct my_game {
    char **map;
    char **save;
    char *buffer;
    int row;
    int col;
    int x;
    int y;
    int o;
    int x_save;
    int y_save;
} my_game_t;


//? Map Contents
void get_columns(my_game_t *, char *);
void put_in_doubletab(my_game_t *, char *);
int columns(char *, int);
int check_errors(my_game_t *, char *);
void get_p(my_game_t *map, char *buffer);

//? Game events
int game_loop(my_game_t *, char *, int);
void down_move(my_game_t *);
void up_move(my_game_t *);
void right_move(my_game_t *);
void left_move(my_game_t *);
int o_check(my_game_t *, char *, int);

//? Others
int my_sokoban(char *);
void free_all(my_game_t *);
int x_numbers(char *);

#endif /* SOKOBAN_H_*/