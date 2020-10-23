/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** end_events.c
*/

#include "defense.h"

void end_events(sfRenderWindow *win, game_t *game, int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyO))
            *status = 0;
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))) {
            *status = -1;
            sfRenderWindow_close(win);
        }
    }
}