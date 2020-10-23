/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_game.c
*/

#include "hunter.h"

t_my_game *my_games(void)
{
    t_my_game *games = malloc(sizeof(t_my_game));

    games->clock = sfClock_create();
    games->seconds = 0;
    return (games);
}

t_my_game *clock_died(void)
{
    t_my_game *clock_died = malloc(sizeof(t_my_game));

    clock_died->clock = sfClock_create();
    clock_died->seconds = 0;
    return (clock_died);
}