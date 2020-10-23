/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** save_data.c
*/

#include "defense.h"

void save_data(game_t *game, int state)
{
    int fd = open("game/data.sav", O_WRONLY | O_TRUNC);
    char *str = NULL;
    char *lvl = NULL;
    char *world = NULL;

    if (state == 1) {
        game->exp = 0;
        game->world = 1;
    }
    lvl = change_int_str(game->exp);
    world = change_int_str(game->world);
    str = my_strcat(my_strdup("exp="), lvl);
    str = my_strcat(str, my_strdup("\nworld="));
    str = my_strcat(str, world);
    str = my_strcat(str, my_strdup("\n"));
    write(fd, str, my_strlen(str));
    free(str);
    close(fd);
}