/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** how_to_play.c
*/

#include "defense.h"

void how_to_events(sfRenderWindow *win, int *loop)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            *loop = 1;
        if (event.type == sfEvtClosed) {
            *loop = -1;
            sfRenderWindow_close(win);
        }
    }
}

void how_to_draw(sfRenderWindow *win, game_t *game, main_menu_t *menu,
sprite_t *how)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->overlay->sprite, NULL);
    sfRenderWindow_drawSprite(win, how->sprite, NULL);
    sfRenderWindow_display(win);
}

void how_to_play(sfRenderWindow *win, game_t *game,
main_menu_t *menu, int *status)
{
    int loop = 0;
    sprite_t *how_to_play = gen_sprite((sfVector2f){0, 0},
    (sfIntRect){0, 0, 1920, 1080}, "sprites/how.png", (sfVector2f){1, 1});

    while (loop == 0) {
        how_to_events(win, &loop);
        how_to_draw(win, game, menu, how_to_play);
    }
    sfTexture_destroy(how_to_play->texture);
    sfSprite_destroy(how_to_play->sprite);
    free(how_to_play);
    if (loop == -1)
        *status = -1;
}