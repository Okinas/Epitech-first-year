/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** game_event.c
*/

#include "hunter.h"

int game_event(t_game_fox *main_game)
{
    sfVector2f pos = sfSprite_getPosition(main_game->sprites->sprite);

    if (pos.x > 1280) {
        main_game->health -= 1;
        if (main_game->offset.x > 4)
            main_game->offset.x -= 3;
        random_pos(main_game);
    }
    if (main_game->copy > 9) {
        main_game->offset.x += 3;
        main_game->copy = 0;
    }
    if (main_game->health == 0)
        return (2);
    sfSprite_move(main_game->sprites->sprite, main_game->offset);
    health_print(main_game);
    return (0);
}