/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** display.c
*/

#include "matchstick.h"

static void draw_content(struct matchstick *request)
{
    int i = 0;

    while (i < request->size) {
        my_putchar('*');
        write(1, request->map[i], my_strlen(request->map[i]));
        write(1, "*\n", 2);
        i += 1;
    }
}

void display_map(struct matchstick *request)
{
    int i = 0;

    while (i < my_strlen(request->map[0]) + 2) {
        my_putchar('*');
        i += 1;
    }
    my_putchar('\n');
    draw_content(request);
    i = 0;
    while (i < my_strlen(request->map[0]) + 2) {
        my_putchar('*');
        i += 1;
    }
    write(1, "\n\n", 2);
}