/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** settings_events.c
*/

#include "defense.h"

static void settings_events_button(sfRenderWindow *win, sfEvent event,
game_t *game, main_menu_t *menu)
{
    if (event.type == sfEvtMouseButtonPressed &&
    get_position(menu->settings->music_on->pos, 81, 45, win) == true) {
        sfSound_play(game->click->sound);
        game->music = !game->music;
    }
    if (event.type == sfEvtMouseButtonPressed &&
    get_position(menu->settings->loading_on->pos, 81, 45, win) == true) {
        sfSound_play(game->click->sound);
        game->loading = !game->loading;
    }
}

void settings_events(sfRenderWindow *win, game_t *game, main_menu_t *menu,
int *loop)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtMouseButtonPressed &&
        get_position((sfVector2f){951, 624}, 190, 62, win) == true)
            *loop = 1;
        if (event.type == sfEvtMouseButtonPressed &&
        get_position(menu->settings->fps->pos, 212, 61, win) == true) {
            sfSound_play(game->click->sound);
            if (game->fps == 120)
                game->fps = 30;
            else
                game->fps *= 2;
            sfText_destroy(game->text->fps);
            game->text->fps = gen_txt((sfVector2f){1000, 548},
            change_int_str(game->fps), "sprites/font.otf", 40);
        } settings_events_button(win, event, game, menu);
        if (event.type == sfEvtClosed) {
            *loop = -1;
            sfSound_play(game->click->sound);
            sfRenderWindow_close(win);
        }
    }
}