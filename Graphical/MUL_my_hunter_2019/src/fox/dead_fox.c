/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** dead_fox.c
*/

#include "hunter.h"

static t_my_sprite *fox_dead(char const *filepath)
{
    t_my_sprite *dead = NULL;

    dead = malloc(sizeof(t_my_sprite));
    dead->texture = sfTexture_createFromFile(filepath, NULL);
    dead->sprite = sfSprite_create();
    sfSprite_setTexture(dead->sprite, dead->texture, sfFalse);
    return (dead);
}

t_my_sprite *my_dead_fox(t_my_sprite *dead)
{
    sfIntRect dead_fox = {487, 0, 81, 106};

    dead = fox_dead("sprites/dead_fox.png");
    dead->rect = dead_fox;
    sfSprite_setTextureRect(dead->sprite, dead_fox);
    return (dead);
}

int dead_fox_animation(t_my_sprite *dead, t_my_game *clock_died)
{
    clock_died->time = sfClock_getElapsedTime(clock_died->clock);
    clock_died->seconds = clock_died->time.microseconds / 1000000.0;
    if (clock_died->seconds > 0.17) {
        dead->rect.left = dead->rect.left - dead->rect.width;
        if (dead->rect.left <= 0)
            return (2);
        sfSprite_setTexture(dead->sprite, dead->texture, sfFalse);
        sfSprite_setTextureRect(dead->sprite, dead->rect);
        sfClock_restart(clock_died->clock);
    }
    return 0;
}