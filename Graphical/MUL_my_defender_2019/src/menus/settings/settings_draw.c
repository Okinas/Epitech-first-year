/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** settings_draw.c
*/

#include "defense.h"

static void settings_draw_buttons(sfRenderWindow *win,
settings_menu_t *settings, game_t *game)
{
    if (game->music == false)
        sfRenderWindow_drawSprite(win, settings->music_off->sprite, NULL);
    else
        sfRenderWindow_drawSprite(win, settings->music_on->sprite, NULL);
    if (game->loading == false)
        sfRenderWindow_drawSprite(win, settings->loading_off->sprite, NULL);
    else
        sfRenderWindow_drawSprite(win, settings->loading_on->sprite, NULL);
}

static void settings_draw_reset(sfRenderWindow *win, settings_menu_t *set,
game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    get_position(set->reset_data->pos, 212, 61, win) == true) {
        sfRenderWindow_drawSprite(win, set->reset_data_click->sprite,
        NULL);
        sfSound_play(game->click->sound);
        save_data(game, 1);
    }
    else if (get_position(set->reset_data->pos, 212, 61, win))
        sfRenderWindow_drawSprite(win, set->reset_data_over->sprite, NULL);
    if ((get_position(set->reset_data->pos, 212, 61, win) == false))
        sfRenderWindow_drawSprite(win, set->reset_data->sprite, NULL);
}

static void settings_draw_credits(sfRenderWindow *win,
settings_menu_t *settings, game_t *game, int *loop)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    get_position(settings->credits->pos, 212, 61, win) == true) {
        sfRenderWindow_drawSprite(win, settings->credits_click->sprite, NULL);
        sfSound_play(game->click->sound);
        *loop = 2;
    }
    else if (get_position(settings->credits->pos, 212, 61, win))
        sfRenderWindow_drawSprite(win, settings->credits_over->sprite, NULL);
    if ((get_position(settings->credits->pos, 212, 61, win) == false))
        sfRenderWindow_drawSprite(win, settings->credits->sprite, NULL);
}

static void settings_draw_fps(sfRenderWindow *win,
settings_menu_t *settings, game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    get_position(settings->fps->pos, 212, 61, win) == true) {
        sfRenderWindow_drawSprite(win, settings->fps_click->sprite,
        NULL);
        sfSound_play(game->click->sound);
        sfRenderWindow_setFramerateLimit(win, game->fps);
    }
    else if (get_position(settings->fps->pos, 212, 61, win))
        sfRenderWindow_drawSprite(win, settings->fps_over->sprite, NULL);
    if ((get_position(settings->fps->pos, 212, 61, win) == false))
        sfRenderWindow_drawSprite(win, settings->fps->sprite, NULL);
    sfRenderWindow_drawText(win, game->text->fps, NULL);
}

void settings_draw(game_t *game, main_menu_t *menu, sfRenderWindow *win,
int *loop)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->overlay->sprite, NULL);
    if (get_position((sfVector2f){951, 624}, 191, 61, win))
        sfRenderWindow_drawSprite(win, menu->settings->panel_over->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(win, menu->settings->panel->sprite, NULL);
    settings_draw_buttons(win, menu->settings, game);
    settings_draw_reset(win, menu->settings, game);
    settings_draw_credits(win, menu->settings, game, loop);
    settings_draw_fps(win, menu->settings, game);
    sfRenderWindow_display(win);
}