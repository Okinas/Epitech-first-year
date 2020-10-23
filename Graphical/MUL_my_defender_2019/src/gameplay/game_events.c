/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_events.c
*/

#include "defense.h"

static void check_towers(sfEvent event, game_menu_t *gameplay,
sfRenderWindow *win)
{
    if (event.type == sfEvtMouseButtonPressed &&
    gameplay->click_tower == false) {
        if (get_position((sfVector2f){91, 883}, 100, 130, win)) {
            gameplay->click_tower = true;
            gameplay->click_tower_type = 0;
        } if (get_position((sfVector2f){216, 883}, 100, 130, win)) {
            gameplay->click_tower = true;
            gameplay->click_tower_type = 1;
        } if (get_position((sfVector2f){349, 883}, 100, 130, win)) {
            gameplay->click_tower = true;
            gameplay->click_tower_type = 2;
        } if (get_position((sfVector2f){481, 883}, 82, 130, win)) {
            gameplay->click_tower = true;
            gameplay->click_tower_type = 3;
        }
    }
    if (event.type == sfEvtMouseButtonReleased &&
    gameplay->click_tower == true) {
        gameplay->click_tower = false;
        put_towers(sfMouse_getPositionRenderWindow(win), gameplay);
    }
}

void game_events(sfRenderWindow *win, int *status,
game_menu_t *gameplay, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_menu(win, game, status);
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyO))
            *status = 2;
        if (event.type == sfEvtClosed) {
            *status = -1;
            sfRenderWindow_close(win);
        }
        check_towers(event, gameplay, win);
    }
}