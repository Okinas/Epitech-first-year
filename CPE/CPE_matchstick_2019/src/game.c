/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** game.c
*/

#include "matchstick.h"

static void process_game(struct matchstick *request)
{
    int out = 0;

    draw_sticks(request);
    display_map(request);
    while (request->end == 0 && check_sticks(request) != 0) {
        out = player_input(request, 0);
        if (out == 84)
            return;
        display_map(request);
        ai_turn(request);
        if (request->end != 0)
            break;
        display_map(request);
    }
}

int game(int ac, char **av)
{
    struct matchstick *request;
    int error = 0;

    srand(time(NULL));
    if (ac != 3 || av == NULL)
        return (84);
    request = request_all(av);
    if (request == NULL)
        return (84);
    process_game(request);
    error = request->end;
    free(request);
    return (error);
}