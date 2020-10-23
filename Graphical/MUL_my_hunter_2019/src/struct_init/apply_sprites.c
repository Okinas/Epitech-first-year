/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** apply_sprites.c
*/

#include "hunter.h"

t_my_sprite *my_background(char const *filepath)
{
    t_my_sprite *background = malloc(sizeof(t_my_sprite));

    background->texture = sfTexture_createFromFile(filepath, NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    return (background);
}

t_my_sprite *my_menu(char const *filepath)
{
    t_my_sprite *menu_game = malloc(sizeof(t_my_sprite));

    menu_game->texture = sfTexture_createFromFile(filepath, NULL);
    menu_game->sprite = sfSprite_create();
    sfSprite_setTexture(menu_game->sprite, menu_game->texture, sfFalse);
    return (menu_game);
}

t_my_sprite *end_game(char const *filepath)
{
    t_my_sprite *end_game = malloc(sizeof(t_my_sprite));

    end_game->texture = sfTexture_createFromFile(filepath, NULL);
    end_game->sprite = sfSprite_create();
    sfSprite_setTexture(end_game->sprite, end_game->texture, sfFalse);
    return (end_game);
}