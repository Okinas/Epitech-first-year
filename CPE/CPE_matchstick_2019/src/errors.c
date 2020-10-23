/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** errors.c
*/

#include "matchstick.h"

static void player_remove(struct matchstick *request, int match, int line)
{
    int i = my_strlen(request->map[0]) - 1;

    write(1, "Player removed ", 15);
    my_putnbr(match, "0123456789");
    while (i >= 0 && match != 0) {
        if (request->map[line][i] == '|') {
            request->map[line][i] = ' ';
            match -= 1;
        }
        i -= 1;
    }
    write(1, " match(es) from line ", 21);
    my_putnbr(line + 1, "0123456789");
    my_putchar('\n');
}

int match_remove(struct matchstick *request, int line, int match)
{
    if (empty_line(request, line) >= 0 && match <=
    empty_line(request, line)) {
        player_remove(request, match, line);
        return (1);
    }
    write(1, "Error: not enough matches on this line\n", 39);
    player_input(request, 1);
    return (0);
}

int match_error(struct matchstick *request, int match)
{
    if (match == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (0);
    }
    if (match > request->limit) {
        write(1, "Error: you cannot remove more than ", 35);
        my_putnbr(request->limit, "0123456789");
        write(1, " matches per turn\n", 18);
        return (0);
    }
    else if (match < 0) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (0);
    }
    return (1);
}

int line_error(int line, struct matchstick *request)
{
    int len = my_strlen(request->map[0]) - 1;

    if (line > len) {
        write(1, "Error: this line is out of range\n", 33);
        return (0);
    }
    if (line <= 0) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (0);
    }
    return (1);
}