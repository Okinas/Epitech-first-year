/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** elements.c
*/

#include "runner.h"

void add_ground(level_t **map, int high, int col)
{
    level_t *new = malloc(sizeof(level_t));

    new->level = sfTexture_createFromFile("sprites/block.png", NULL);
    new->slevel = sfSprite_create();
    sfSprite_setTexture(new->slevel, new->level, sfTrue);
    new->pos.x = col * 400;
    new->pos.y = 620;
    sfSprite_setPosition(new->slevel, new->pos);
    new->offset.x = -15;
    new->offset.y = 0;
    new->what = 1;
    new->high = high;
    new->col = col;
    new->next = *map;
    new->prev = NULL;
    (*map)->prev = new;
    *map = new;
}

void add_spike(level_t **map, int col)
{
    level_t *new = malloc(sizeof(level_t));

    new->level = sfTexture_createFromFile("sprites/spike.png", NULL);
    new->slevel = sfSprite_create();
    sfSprite_setTexture(new->slevel, new->level, sfTrue);
    new->pos.x = col * 400;
    new->pos.y = 520;
    sfSprite_setPosition(new->slevel, new->pos);
    new->offset.x = -15;
    new->offset.y = 0;
    new->what = 2;
    new->high = 2;
    new->col = col;
    new->next = *map;
    new->prev = NULL;
    (*map)->prev = new;
    *map = new;
}

void add_void(level_t **map, int high, int col)
{
    level_t *new = malloc(sizeof(level_t));

    new->level = sfTexture_createFromFile("sprites/void.png", NULL);
    new->slevel = sfSprite_create();
    sfSprite_setTexture(new->slevel, new->level, sfTrue);
    new->pos.x = col * 400;
    new->pos.y = 620;
    sfSprite_setPosition(new->slevel, new->pos);
    new->offset.x = -15;
    new->offset.y = 0;
    new->what = 3;
    new->high = high;
    new->col = col;
    new->next = *map;
    new->prev = NULL;
    (*map)->prev = new;
    *map = new;
}
