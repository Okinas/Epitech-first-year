/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "my.h"

struct matchstick {
    char **map;
    int end;
    int limit;
    int size;
};

int game(int, char **);

void ai_turn(struct matchstick *);
int check_sticks(struct matchstick *);
void draw_sticks(struct matchstick *);
void display_map(struct matchstick *);
struct matchstick *request_all(char **);

int empty_line(struct matchstick *, int);
int line_error(int, struct matchstick *);
int match_error(struct matchstick *, int);
int match_remove(struct matchstick *, int, int);
int player_input(struct matchstick *, int);

#endif /* MATCHSTICK_H_ */
