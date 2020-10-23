/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** end_draw.c
*/

#include "defense.h"

void end_draw(game_t *game, end_menu_t *end, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, game->map->sprite, NULL);
    sfRenderWindow_drawText(win, end->total_coins, NULL);
    sfRenderWindow_drawText(win, end->total_kill, NULL);
    sfRenderWindow_display(win);
}