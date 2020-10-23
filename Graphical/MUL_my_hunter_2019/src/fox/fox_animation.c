/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** fox_animation.c
*/

#include "hunter.h"

static t_my_sprite *fox_sprites(char const *filepath)
{
    t_my_sprite *sprites = NULL;

    sprites = malloc(sizeof(t_my_sprite));
    sprites->texture = sfTexture_createFromFile(filepath, NULL);
    sprites->sprite = sfSprite_create();
    sfSprite_setTexture(sprites->sprite, sprites->texture, sfFalse);
    return (sprites);
}

t_my_sprite *my_fox(t_my_sprite *sprites)
{
    sfIntRect fox = {0, 0, 87, 87};

    sprites = fox_sprites("sprites/fox.png");
    sprites->rect = fox;
    sfSprite_setTextureRect(sprites->sprite, fox);
    return (sprites);
}

void fox_animation(t_my_sprite *sprites, t_my_game *games)
{
    games->time = sfClock_getElapsedTime(games->clock);
    games->seconds = games->time.microseconds / 1000000.0;
    if (games->seconds > 0.2) {
        sprites->rect.left = sprites->rect.left + sprites->rect.width;
        if (sprites->rect.left > 87)
            sprites->rect.left = 0;
        sfSprite_setTexture(sprites->sprite, sprites->texture, sfFalse);
        sfSprite_setTextureRect(sprites->sprite, sprites->rect);
        sfClock_restart(games->clock);
    }
}
