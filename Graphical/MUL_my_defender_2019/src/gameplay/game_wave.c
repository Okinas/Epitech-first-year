/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_wave.c
*/

#include "defense.h"

void print_new_wave(sfRenderWindow *win, game_menu_t *gameplay, game_t *game)
{
    sfText_scale(gameplay->wave_start->wave_text, (sfVector2f){1.01, 1.01});
    if (get_seconds(gameplay->wave_start->wave_print) > 2)
        gameplay->end_wave = false;
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, game->map->sprite, NULL);
    sfRenderWindow_drawText(win, gameplay->wave_start->wave_text, NULL);
    sfRenderWindow_display(win);
}