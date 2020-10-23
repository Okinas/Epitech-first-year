/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** free_all.c
*/

#include "defense.h"

void free_sprite_struct(sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
}

void free_struct(game_t *game)
{
    free_sprite_struct(game->map);
    free(game->text);
    free(game->map);
    free(game);
}