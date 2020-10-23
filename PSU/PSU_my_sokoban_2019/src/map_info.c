/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** map_info.c
*/

#include "sokoban.h"

int columns(char *map, int temp)
{
    int i = 0;

    while (map[temp] != '\n' && map[temp] != '\0') {
        temp += 1;
        i += 1;
    }
    return (i);
}

void get_columns(my_game_t *game, char *map)
{
    int i = 0;

    game->col = 0;
    game->row = 0;
    while (map[game->col] != '\n') {
        game->col += 1;
    }
    while (map[i] != '\0') {
        if (map[i] == '\n')
            game->row += 1;
        i += 1;
    }
    if (map[i - 1] != '\n')
        game->row += 1;
}

void get_p(my_game_t *game, char *buffer)
{
    int i = 0;
    int j = 0;
    int col = 0;
    int temp = 0;

    while (i != game->row) {
        col = 0;
        temp = columns(buffer, j);
        while (col != temp) {
            if (game->map[i][col] == 'P') {
                game->x = col;
                game->y = i;
            }
            j += 1;
            col += 1;
        }
        j += 1;
        i += 1;
    }
    game->x_save = game->x;
    game->y_save = game->y;
}