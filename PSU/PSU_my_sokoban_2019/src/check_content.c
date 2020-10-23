/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check_content.c
*/

#include "sokoban.h"

static int map_check(char *buffer)
{
    char c;
    int i = 0;

    while (buffer[i] != '\0') {
        c = buffer[i];
        if (c == '#' || c == 'P' || c == 'O' || c == 'X' || c == ' '
        || c == '\n' || c == '\0')
            i += 1;
        else
            return (84);
    }
    return (0);
}

int x_numbers(char *buffer)
{
    int i = 0;
    int x = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'X')
            x += 1;
        i += 1;
    }
    return (x);
}

static int o_numbers(char *buffer)
{
    int i = 0;
    int o = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'O')
            o += 1;
        i += 1;
    }
    return (o);
}

static int p_numbers(char *buffer)
{
    int i = 0;
    int p = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'P')
            p += 1;
        i += 1;
    }
    return (p);
}

int check_errors(my_game_t *game, char *buffer)
{
    int errors = map_check(buffer);
    int o = o_numbers(buffer);
    int x = x_numbers(buffer);
    int p = p_numbers(buffer);

    get_columns(game, buffer);
    game->o = o;
    if (o == 0 || x == 0 || p == 0 || errors == 84)
        return (84);
    return (0);
}