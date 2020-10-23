/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** game.c
*/

#include "runner.h"

void game_loop_map(t_my_runner *game)
{
    sfRenderWindow_close(game->win->window);
}

int game_map(char **av)
{
    t_my_runner *game = malloc(sizeof(t_my_runner));

    if (game == NULL)
        return (84);
    game->player = malloc(sizeof(player_t));
    game->mob = malloc(sizeof(mob_t));
    game->map = malloc(sizeof(level_t));
    game->win = malloc(sizeof(win_map_t));
    setup_wido(game->win);
    map_setup(&game->map, av);
    setup_mob(game->mob);
    setup_player(game->player);
    game->win->clock = sfClock_create();
    game->mob->clock = sfClock_create();
    game_loop_map(game);
    return (0);
}