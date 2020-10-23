/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** end_menu.c
*/

#include "defense.h"

void end_menu(sfRenderWindow *win, game_t *game, int *status)
{
    end_menu_t *end = end_load(game);

    if (game->loading == true)
        loading(win, status);
    while (*status == 2) {
        end_events(win, game, status);
        end_draw(game, end, win);
    }
}