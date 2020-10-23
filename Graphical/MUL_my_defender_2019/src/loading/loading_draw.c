/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** loading_draw.c
*/

#include "defense.h"

static void loading_animation(loading_t *load)
{
    if (get_seconds(load->clock_round) > 0.005) {
        if (load->round->rect.left >= 6501)
            load->round->rect.left = 0;
        else
            load->round->rect.left += 197;
        sfClock_restart(load->clock_round);
    }
    sfSprite_setTextureRect(load->round->sprite, load->round->rect);
}

void loading_draw(sfRenderWindow *win, loading_t *load)
{
    loading_animation(load);
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, load->background->sprite, NULL);
    sfRenderWindow_drawSprite(win, load->round->sprite, NULL);
    sfRenderWindow_drawText(win, load->advice, NULL);
    sfRenderWindow_display(win);
}