/*
** EPITECH PROJECT, 2019
** Tower_Defense
** File description:
** events.c
*/

#include "defense.h"

static int events_2(main_menu_t *menu, sfRenderWindow *win, sfEvent event,
game_t *game)
{
    int tmp = 0;

    if (event.type == sfEvtMouseButtonPressed &&
    get_position(menu->settings_button->pos, 83, 83, win) == true) {
        sfSound_play(game->click->sound);
        settings_menu(win, game, menu, &tmp);
    }
    if (event.type == sfEvtMouseButtonPressed &&
    get_position(menu->help_button->pos, 83, 83, win) == true) {
        sfSound_play(game->click->sound);
        how_to_play(win, game, menu, &tmp);
    }
    if (event.type == sfEvtMouseButtonPressed &&
    get_position(menu->play->pos, 338, 89, win)) {
        sfSound_play(menu->start_sound->sound);
        tmp = 1;
    }
    return (tmp);
}

void main_events(sfRenderWindow *win, game_t *game, main_menu_t *menu,
int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        *status = events_2(menu, win, event, game);
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyO))
            *status = 2;
        if (event.type == sfEvtClosed || (event.type == sfEvtMouseButtonPressed
        && get_position(menu->quit_button->pos, 83, 83, win) == true)) {
            sfSound_play(game->click->sound);
            *status = -1;
            sfRenderWindow_close(win);
        }
    }
}