/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game_events.c
*/

#include "sokoban.h"

static void complementary_condition(my_game_t *game, int x, int y, int *lose)
{
    int change = 0;

    if ((game->map[y][x] == 'X') && ((game->save[y + 1][x] == '#')
    && (game->save[y][x + 1] == '#')) && change == 0) {
        (*lose) += 1;
        change = 1;
    }
    if ((game->map[y][x] == 'X') && ((game->save[y + 1][x] == '#')
    && (game->save[y][x - 1] == '#')) && change == 0) {
        (*lose) += 1;
        change = 1;
    }
}

static int all_boxes(my_game_t *game, int x, int y, int *lose)
{
    int change = 0;

    if ((game->map[y][x] == 'X') && ((game->save[y - 1][x] == '#')
    && (game->save[y][x + 1] == '#')) && change == 0) {
        (*lose) += 1;
        change = 1;
    }
    if ((game->map[y][x] == 'X') && ((game->save[y - 1][x] == '#')
    && (game->save[y][x - 1] == '#')) && change == 0) {
        (*lose) += 1;
        change = 1;
    }
    if (change == 0)
        complementary_condition(game, x, y, lose);
    if ((*lose) == x_numbers(game->buffer))
        return (1);
    return (0);
}

static int lose_conditions(my_game_t *game, char *buffer)
{
    int x = 0;
    int y = 0;
    int j = 0;
    int col;
    int lose = 0;

    while (y != game->row) {
        x = 0;
        col = columns(buffer, j);
        while (x != col) {
            if (all_boxes(game, x, y, &lose) == 1)
                return (1);
            x += 1;
            j += 1;
        } j += 1;
        y += 1;
    }
    return (0);
}

int o_check(my_game_t *game, char *buffer, int status)
{
    int y = 0;
    int j = 0;
    int x = 0;
    int box = 0;
    int col = 0;

    while (y != game->row) {
        x = 0;
        col = columns(buffer, j);
        while (x != col) {
            if ((game->map[y][x] == 'X') && (game->save[y][x] == 'O'))
                box += 1;
            if (box == game->o)
                return (-1);
            x += 1;
            j += 1;
        } j += 1;
        y += 1;
    }
    status = lose_conditions(game, buffer);
    return (status);
}