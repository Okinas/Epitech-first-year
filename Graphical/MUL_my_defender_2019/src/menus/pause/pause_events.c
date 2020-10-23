/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause_events.c
*/

#include "defense.h"

void pause_events(sfRenderWindow *win, game_t *game, pause_menu_t *pause,
int *loop)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            *loop = 1;
        if (event.type == sfEvtClosed || (event.type == sfEvtMouseButtonPressed
        && get_position(pause->quit_button->pos, 83, 83, win) == true)) {
            *loop = -1;
            sfSound_play(game->click->sound);
            sfRenderWindow_close(win);
        }
    }
}