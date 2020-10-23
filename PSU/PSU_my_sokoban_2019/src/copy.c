/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** copy.c
*/

#include "sokoban.h"

void put_in_doubletab(my_game_t *game, char *map)
{
    int i = 0;
    int col = 0;
    int temp = 0;
    int temp2 = 0;

    game->map = malloc(sizeof(char *) * (game->row + 1));
    game->save = malloc(sizeof(char *) * (game->row + 1));
    while (i < game->row) {
        temp2 = columns(map, temp);
        game->map[i] = malloc(sizeof(char) * (temp2 + 1));
        game->save[i] = malloc(sizeof(char) * (temp2 + 1));
        col = 0;
        while (col < temp2) {
            game->map[i][col] = map[temp];
            game->save[i][col] = map[temp];
            col += 1;
            temp += 1;
        } temp += 1;
        i += 1;
    }
}

void free_all(my_game_t *game)
{
    int i = 0;

    while (i < game->row) {
        free(game->map[i]);
        free(game->save[i]);
        i += 1;
    }
    free(game->save);
    free(game->map);
}