/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gen_sprite.c
*/

#include "defense.h"

sprite_t *gen_sprite_icon(sfVector2f pos, int level)
{
    sfIntRect rect;
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (level < 5)
        rect = (sfIntRect){1198, 18, 138, 153};
    if (level >= 5 && level < 10)
        rect = (sfIntRect){1342, 18, 138, 153};
    if (level >= 10 && level < 15)
        rect = (sfIntRect){1484, 18, 138, 153};
    if (level >= 15 && level < 20)
        rect = (sfIntRect){1626, 18, 138, 153};
    if (level >= 20 && level < 25)
        rect = (sfIntRect){1769, 18, 138, 153};
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile("sprites/sheet.png", NULL);
    sprite->rect = rect;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, pos);
    return (sprite);
}

sprite_t *gen_sprite(sfVector2f pos, sfIntRect rect, char *path,
sfVector2f size)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->rect = rect;
    sprite->pos = pos;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, pos);
    sfSprite_setScale(sprite->sprite, size);
    return (sprite);
}