/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** window.c
*/

#include "defense.h"

int create_window(unsigned int width, unsigned int height)
{
    sfVideoMode vid_mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create(vid_mode, "Tower Defense",
    sfDefaultStyle, NULL);
    game_t *game = NULL;

    if (window == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(window, 60);
    game = init_struct();
    if (game == NULL)
        return (84);
    return (game_loop(window, game));
}