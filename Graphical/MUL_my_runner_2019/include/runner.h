/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** runner.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "my.h"

#ifndef RUNNER_H_
#define RUNNER_H_

//? Menus
void add_void(level_t **map, int high, int col);
void add_ground(level_t **map, int high, int col);
void add_spike(level_t **map, int col);
void setup_wido(win_map_t *win);
void map_setup(level_t **map, char **av);
void setup_player(player_t *player);
void setup_mob(mob_t *mob);
int start_game(char **av);

#endif /* RUNNER_H_ */