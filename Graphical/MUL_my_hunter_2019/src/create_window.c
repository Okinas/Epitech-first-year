/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** create_window.c
*/

#include "hunter.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode v_mode;

    v_mode.width = width;
    v_mode.height = height;
    v_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(v_mode, "Hunter & Fox", sfDefaultStyle,
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}