/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause_draw.c
*/

#include "defense.h"

void pause_draw_buttons(sfRenderWindow *win, game_t *game,
pause_menu_t *pause, int *loop)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    get_position(pause->main_menu->pos, 212, 61, win) == true) {
        sfSound_play(game->click->sound);
        sfRenderWindow_drawSprite(win, pause->main_menu_click->sprite, NULL);
        *loop = 2;
    }
    else if (get_position(pause->main_menu->pos, 212, 61, win))
        sfRenderWindow_drawSprite(win, pause->main_menu_over->sprite, NULL);
    if ((get_position(pause->main_menu->pos, 212, 61, win) == false))
        sfRenderWindow_drawSprite(win, pause->main_menu->sprite, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    get_position(pause->resume->pos, 212, 61, win) == true) {
        sfSound_play(game->click->sound);
        sfRenderWindow_drawSprite(win, pause->resume_click->sprite, NULL);
        *loop = 1;
    }
    else if (get_position(pause->resume->pos, 212, 61, win))
        sfRenderWindow_drawSprite(win, pause->resume_over->sprite, NULL);
    if ((get_position(pause->resume->pos, 212, 61, win) == false))
        sfRenderWindow_drawSprite(win, pause->resume->sprite, NULL);
}

void pause_draw(game_t *game, pause_menu_t *pause, sfRenderWindow *win,
int *loop)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(win, pause->overlay->sprite, NULL);
    sfRenderWindow_drawSprite(win, pause->pause->sprite, NULL);
    if (get_position(pause->quit_button->pos, 83, 83, win))
        sfRenderWindow_drawSprite(win, pause->quit_button_over->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(win, pause->quit_button->sprite,
        NULL);
    pause_draw_buttons(win, game, pause, loop);
    sfRenderWindow_display(win);
}