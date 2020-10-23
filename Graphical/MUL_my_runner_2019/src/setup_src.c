/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** setup_src.c
*/

#include "runner.h"

void setup_player(player_t *player)
{
    player->falling = 0;
    player->over = 0;
    player->run = 0;
    player->limit = 8;
    player->pos.x = 0;
    player->pos.y = 320;
    player->grav.x = 0;
    player->grav.y = 0;
    player->state.left = 0;
    player->state.top = 0;
    player->state.width = 400;
    player->state.height = 400;
    player->player = sfTexture_createFromFile("img/object/aigis.png", NULL);
    player->splayer = sfSprite_create();
    sfSprite_setTexture(player->splayer, player->player, sfTrue);
    sfSprite_setPosition(player->splayer, player->pos);
    sfSprite_setTextureRect(player->splayer, player->state);
}

void setup_mob(mob_t *mob)
{
    mob->state.left = 0;
    mob->state.top = 0;
    mob->state.width = 700;
    mob->state.height = 700;
    mob->fact.x = 0.75;
    mob->fact.y = 0.75;
    mob->pos.x = 2000;
    mob->pos.y = 235;
    mob->speed.x = -15;
    mob->speed.y = 0;
    mob->sum = 0;
    mob->mob = sfTexture_createFromFile("sprites/mob.png", NULL);
    mob->smob = sfSprite_create();
    sfSprite_setTexture(mob->smob, mob->mob, sfTrue);
    sfSprite_setPosition(mob->smob, mob->pos);
    sfSprite_setTextureRect(mob->smob, mob->state);
    sfSprite_scale(mob->smob, mob->fact);
}