/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** count.c
*/

#include "matchstick.h"

int check_sticks(struct matchstick *request)
{
    int i = 0;
    int j = 0;
    int length = 0;

    while (i < request->size) {
        j = 0;
        while (request->map[i][j]) {
            if (request->map[i][j] == '|')
                length += 1;
            j += 1;
        }
        i += 1;
    }
    return (length);
}

int empty_line(struct matchstick *request, int line)
{
    int i = 0;
    int length = 0;

    if (line >= request->size) {
        write(1, "Error: this line is out of range\n", 33);
        return (-1);
    }
    while (request->map[line][i]) {
        if (request->map[line][i] == '|')
            length += 1;
        i += 1;
    }
    return (length);
}