/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** free.c
*/

#include "navy.h"

void free_all(void)
{
    for (int i = 0; s_main.my_map[i]; i++) {
        free(s_main.my_map[i]);
        free(s_main.ennemy_map[i]);
    }
    free(s_main.my_map);
    free(s_main.ennemy_map);
}