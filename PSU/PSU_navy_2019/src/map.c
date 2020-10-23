/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** map.c
*/

#include "navy.h"

int fill_boat(char *first_point_boat, char *end_point_boat, int boat_size)
{
    int f_letter = first_point_boat[0] - 'A';
    int f_number = first_point_boat[1] - '0' - 1;
    int e_number = end_point_boat[1] - '0' - 1;

    if (f_number == e_number) {
        for (int i = 0; i < boat_size; i += 1) {
            if (s_main.my_map[f_number][f_letter] != '.')
                return (1);
            s_main.my_map[f_number][f_letter] = boat_size + '0';
            f_letter += 1;
        }
    } else {
        for (int i = 0; i < boat_size; i += 1) {
            if (s_main.my_map[f_number][f_letter] != '.')
                return (1);
            s_main.my_map[f_number][f_letter] = boat_size + '0';
            f_number += 1;
        }
    }
    return (0);
}

int fill_my_map(void)
{
    char *map = read_file(s_main.file);
    char *first_point_boat = malloc(sizeof(char) * 2);
    char *end_point_boat = malloc(sizeof(char) * 2);
    int boat_size = 0;

    for (int i = 0; map[i] != '\0'; i += 8) {
        boat_size = map[i] - 48;
        first_point_boat[0] = map[i + 2];
        first_point_boat[1] = map[i + 3];
        end_point_boat[0] = map[i + 5];
        end_point_boat[1] = map[i + 6];
        if (fill_boat(first_point_boat, end_point_boat, boat_size))
            return (1);
        if (map[i + 7] == '\0')
            break;
    }
    free(map);
    free(first_point_boat);
    free(end_point_boat);
    return (0);
}

int fill_map(void)
{
    s_main.my_map = malloc(sizeof(char *) * 9);
    s_main.ennemy_map = malloc(sizeof(char *) * 9);
    s_main.my_map[8] = NULL;
    s_main.ennemy_map[8] = NULL;
    for (int i = 0; i < 8; i += 1)
        s_main.my_map[i] = malloc(sizeof(char) * 9);
    for (int i = 0; i < 8; i += 1)
        s_main.ennemy_map[i] = malloc(sizeof(char) * 9);
    if (!s_main.my_map || !s_main.ennemy_map)
        return (1);
    for (int i = 0; i < 8; i += 1) {
        for (int j = 0; j < 8; j += 1) {
            s_main.my_map[i][j] = '.';
            s_main.ennemy_map[i][j] = '.';
        }
        s_main.my_map[i][8] = '\0';
        s_main.ennemy_map[i][8] = '\0';
    }
    return (fill_my_map());
}

void hit_map(int pos, char letter, char **map)
{
    int line = pos % 10 - 1;
    int col = pos / 10;

    map[line][col] = letter;
}

void print_map(char **map, char *positions)
{
    char letter = '1';

    my_putstr(positions);
    my_putstr(" positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; map[i]; i += 1) {
        my_putchar(letter);
        my_putchar('|');
        for (int j = 0; map[i][j]; j += 1) {
            my_putchar(map[i][j]);
            if (map[i][j + 1] != '\0')
                my_putchar(' ');
        }
        my_putchar('\n');
        letter += 1;
    }
    my_putchar('\n');
}