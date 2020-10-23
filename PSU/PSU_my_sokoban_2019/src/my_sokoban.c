/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_sokoban.c
*/

#include "sokoban.h"

int my_sokoban(char *buffer)
{
    my_game_t *game = malloc(sizeof(my_game_t));
    int status = 0;

    if (game == NULL)
        return (84);
    game->buffer = buffer;
    if (check_errors(game, buffer) != 0)
        return (84);
    put_in_doubletab(game, buffer);
    get_p(game, buffer);
    status = game_loop(game, buffer, status);
    free_all(game);
    free(game);
    return (status);
}