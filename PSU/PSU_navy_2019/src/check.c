/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check.c
*/

#include "navy.h"

int check_hit(int pos)
{
    int line = pos % 10 - 1;
    int col = pos / 10;

    if (s_main.my_map[line][col] >= '2' && s_main.my_map[line][col] <= '5') {
        hit_map(pos, 'x', s_main.my_map);
        return (1);
    } else {
        hit_map(pos, 'o', s_main.my_map);
        return (0);
    }
}

int check_pos(char *pos)
{
    if (pos == NULL)
        return (0);
    if (my_strlen(pos) != 2)
        return (1);
    if (pos[0] < 'A' || pos[0] > 'H')
        return (1);
    if (pos[1] < '1' || pos[1] > '8')
        return (1);
    return (0);
}