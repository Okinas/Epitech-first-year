/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** inputs.c
*/

#include "matchstick.h"

int input_match(struct matchstick *request, int line)
{
    int match = 0;
    char *str = NULL;

    write(1, "Matches: ", 9);
    str = get_next_line(0);
    if (str == NULL) {
        free(str);
        request->end = 0;
        return (84);
    }
    match = my_getnbr(str);
    free(str);
    if (match_error(request, match) == 0)
        return (player_input(request, 1));
    return (match_remove(request, line, match));
}

int player_input(struct matchstick *request, int line)
{
    char *str = NULL;

    if (line == 0)
        write(1, "Your turn:\n", 11);
    write(1, "Line: ", 6);
    str = get_next_line(0);
    if (str == NULL) {
        free(str);
        request->end = 0;
        return (84);
    }
    line = my_getnbr(str);
    free(str);
    if (line_error(line, request) == 0)
        return (player_input(request, 1));
    line -= 1;
    if (empty_line(request, line) == -1)
        return (player_input(request, 1));
    return (input_match(request, line));
}