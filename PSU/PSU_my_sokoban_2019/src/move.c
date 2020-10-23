/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move.c
*/

#include "sokoban.h"

void up_move(my_game_t *game)
{
    int x = game->x;
    int y = game->y;

    if (game->map[y - 1][x] != 'X') {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y - 1][x] = 'P';
        game->y -= 1;
    } else if ((game->map[y - 1][x] == 'X') && (game->map[y - 2][x] != '#')
    && (game->map[y - 2][x] != 'X')) {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y - 2][x] = 'X';
        game->map[y - 1][x] = 'P';
        game->y -= 1;
    }
}

void down_move(my_game_t *game)
{
    int x = game->x;
    int y = game->y;

    if (game->map[y + 1][x] != 'X') {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y + 1][x] = 'P';
        game->y += 1;
    } else if ((game->map[y + 1][x] == 'X') && (game->map[y + 2][x] != '#')
    && (game->map[y + 2][x] != 'X')) {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y + 2][x] = 'X';
        game->map[y + 1][x] = 'P';
        game->y += 1;
    }
}

void right_move(my_game_t *game)
{
    int x = game->x;
    int y = game->y;

    if (game->map[y][x + 1] != 'X') {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y][x + 1] = 'P';
        game->x += 1;
    } else if ((game->map[y][x + 1] == 'X') && (game->map[y][x + 2] != '#')
    && (game->map[y][x + 2] != 'X')) {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y][x + 2] = 'X';
        game->map[y][x + 1] = 'P';
        game->x += 1;
    }

}

void left_move(my_game_t *game)
{
    int x = game->x;
    int y = game->y;

    if (game->map[y][x - 1] != 'X') {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y][x - 1] = 'P';
        game->x -= 1;
    } else if ((game->map[y][x - 1] == 'X') && (game->map[y][x - 2] != '#')
    && (game->map[y][x - 2] != 'X')) {
        if (game->save[y][x] == 'O')
            game->map[y][x] = 'O';
        else
            game->map[y][x] = ' ';
        game->map[y][x - 2] = 'X';
        game->map[y][x - 1] = 'P';
        game->x -= 1;
    }
}