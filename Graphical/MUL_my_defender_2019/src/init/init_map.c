/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_map.c
*/

#include "defense.h"

void init_map(game_t *game)
{
    game->map = malloc(sizeof(sprite_t));
    game->gui = malloc(sizeof(sprite_t));
    game->map->texture = NULL;
    game->map->sprite = sfSprite_create();
    if (game->world == 1)
        game->map->texture = sfTexture_createFromFile("sprites/map1.jpg", NULL);
    sfSprite_setTexture(game->map->sprite, game->map->texture, sfFalse);
    game->gui->texture = sfTexture_createFromFile("sprites/GUI.png", NULL);
    game->gui->sprite = sfSprite_create();
    sfSprite_setTexture(game->gui->sprite, game->gui->texture, sfFalse);
}