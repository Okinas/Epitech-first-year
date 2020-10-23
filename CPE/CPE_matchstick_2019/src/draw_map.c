/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** draw_map.c
*/

#include "matchstick.h"

static void draw_x_axis(struct matchstick *request, int y)
{
    int x = 0;
    int d_size = (2 * request->size);

    while (x < d_size) {
        if (x >= (d_size - request->size + 1 + y - 1)
        || x <= (request->size - 2 - y))
            request->map[y][x] = ' ';
        else
            request->map[y][x] = '|';
        x += 1;
    }
    request->map[y][x - 1] = '\0';
}

void draw_sticks(struct matchstick *request)
{
    int y = 0;

    while (y < request->size) {
        draw_x_axis(request, y);
        y += 1;
    }
}