/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** get_positions.c
*/

#include "defense.h"

float get_seconds(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);

    return (time.microseconds / 1000000.0);
}

bool get_position(sfVector2f pos, int width, int height, sfRenderWindow *win)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    if ((mouse_pos.x >= pos.x && mouse_pos.y >= pos.y) &&
    (mouse_pos.x <= pos.x + width && mouse_pos.y <= pos.y + height))
        return (true);
    return (false);
}