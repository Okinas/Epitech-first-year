/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu.c
*/

#include "hunter.h"

int menu(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (2);
        } if (event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeySpace))
            return (1);
    }
    return (0);
}

void draw_menu(sfRenderWindow *window, t_game_fox *main_game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, main_game->menu->sprite, NULL);
    sfRenderWindow_display(window);
}
