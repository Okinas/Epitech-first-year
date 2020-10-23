/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** gameloop.c
*/

#include "defense.h"

int game_loop(sfRenderWindow *win, game_t *game)
{
    int status = 0;

    if (status == 0)
        main_menu(win, game, &status);
    if (status == 1)
        game_menu(win, game, &status);
    if (status == 2)
        end_menu(win, game, &status);
    if (status == -1) {
        save_data(game, 0);
        free_struct(game);
        sfRenderWindow_destroy(win);
        return (0);
    }
    game_loop(win, game);
    return (0);
}