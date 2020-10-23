/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** pause_menu.c
*/

#include "defense.h"

void pause_free2(pause_menu_t *pause)
{
    sfTexture_destroy(pause->quit_button->texture);
    sfSprite_destroy(pause->quit_button->sprite);
    sfTexture_destroy(pause->quit_button_over->texture);
    sfSprite_destroy(pause->quit_button_over->sprite);
    free(pause->main_menu);
    free(pause->main_menu_click);
    free(pause->main_menu_over);
    free(pause->overlay);
    free(pause->pause);
    free(pause->quit_button);
    free(pause->quit_button_over);
    free(pause->resume);
    free(pause->resume_over);
    free(pause->resume_click);
}

void pause_free(pause_menu_t *pause)
{
    sfSprite_destroy(pause->pause->sprite);
    sfTexture_destroy(pause->pause->texture);
    sfSprite_destroy(pause->overlay->sprite);
    sfTexture_destroy(pause->overlay->texture);
    sfSprite_destroy(pause->resume->sprite);
    sfTexture_destroy(pause->resume->texture);
    sfSprite_destroy(pause->resume_over->sprite);
    sfTexture_destroy(pause->resume_over->texture);
    sfSprite_destroy(pause->resume_click->sprite);
    sfTexture_destroy(pause->resume_click->texture);
    sfSprite_destroy(pause->main_menu->sprite);
    sfTexture_destroy(pause->main_menu->texture);
    sfSprite_destroy(pause->main_menu_click->sprite);
    sfTexture_destroy(pause->main_menu_click->texture);
    sfSprite_destroy(pause->main_menu_over->sprite);
    sfTexture_destroy(pause->main_menu_over->texture);
    pause_free2(pause);
}

void pause_menu(sfRenderWindow *win, game_t *game, int *status)
{
    int loop = 0;
    pause_menu_t *pause = pause_load();

    while (loop == 0) {
        pause_events(win, game, pause, &loop);
        pause_draw(game, pause, win, &loop);
    }
    if (loop == -1)
        *status = -1;
    if (loop == 2)
        *status = 0;
    pause_free(pause);
}