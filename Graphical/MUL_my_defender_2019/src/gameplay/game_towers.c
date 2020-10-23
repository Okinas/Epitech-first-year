/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gam_towers.c
*/

#include "defense.h"

sfSprite *gen_sprite_tower(game_menu_t *gameplay, sfVector2f pos, int i)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("sprites/tower.png", NULL);
    sfIntRect rect = gameplay->towers[gameplay->click_tower_type].rect;

    gameplay->tower_slots[i].pos = pos;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

static void put_towers_3(sfVector2i mouse, game_menu_t *gameplay)
{
    if (mouse.x > 1010 && mouse.x < 1225 && mouse.y > 815 && mouse.y < 927 &&
    gameplay->tower_slots[4].free == true &&
    gameplay->coins >= gameplay->towers[gameplay->click_tower_type].cost) {
        gameplay->tower_slots[4].free = false;
        gameplay->tower_slots[4].sprite = gen_sprite_tower(gameplay,
        (sfVector2f){1090, 754}, 4);
        gameplay->tower_slots[4].type = gameplay->click_tower_type;
        gameplay->coins -= gameplay->towers[gameplay->click_tower_type].cost;
    }
    if (mouse.x > 1705 && mouse.x < 1920 && mouse.y > 775 && mouse.y < 887 &&
    gameplay->tower_slots[5].free == true &&
    gameplay->coins >= gameplay->towers[gameplay->click_tower_type].cost) {
        gameplay->tower_slots[5].free = false;
        gameplay->tower_slots[5].sprite = gen_sprite_tower(gameplay,
        (sfVector2f){1797, 715}, 5);
        gameplay->tower_slots[5].type = gameplay->click_tower_type;
        gameplay->coins -= gameplay->towers[gameplay->click_tower_type].cost;
    }
}

static void put_towers_2(sfVector2i mouse, game_menu_t *gameplay)
{
    if (mouse.x > 1314 && mouse.x < 1529 && mouse.y > 300 && mouse.y < 412 &&
    gameplay->tower_slots[2].free == true &&
    gameplay->coins >= gameplay->towers[gameplay->click_tower_type].cost) {
        gameplay->tower_slots[2].free = false;
        gameplay->tower_slots[2].sprite = gen_sprite_tower(gameplay,
        (sfVector2f){1385, 233}, 2);
        gameplay->tower_slots[2].type = gameplay->click_tower_type;
        gameplay->coins -= gameplay->towers[gameplay->click_tower_type].cost;
    }
    if (mouse.x > 500 && mouse.x < 715 && mouse.y > 750 && mouse.y < 862 &&
    gameplay->tower_slots[3].free == true &&
    gameplay->coins >= gameplay->towers[gameplay->click_tower_type].cost) {
        gameplay->tower_slots[3].free = false;
        gameplay->tower_slots[3].sprite = gen_sprite_tower(gameplay,
        (sfVector2f){578, 683}, 3);
        gameplay->tower_slots[3].type = gameplay->click_tower_type;
        gameplay->coins -= gameplay->towers[gameplay->click_tower_type].cost;
    }
    put_towers_3(mouse, gameplay);
}

void put_towers(sfVector2i mouse, game_menu_t *gameplay)
{
    if (mouse.x > 192 && mouse.x < 407 && mouse.y > 228 && mouse.y < 340 &&
    gameplay->tower_slots[0].free == true &&
    gameplay->coins >= gameplay->towers[gameplay->click_tower_type].cost) {
        gameplay->tower_slots[0].free = false;
        gameplay->tower_slots[0].sprite = gen_sprite_tower(gameplay,
        (sfVector2f){267, 164}, 0);
        gameplay->tower_slots[0].type = gameplay->click_tower_type;
        gameplay->coins -= gameplay->towers[gameplay->click_tower_type].cost;
    }
    if (mouse.x > 842 && mouse.x < 1057 && mouse.y > 222 && mouse.y < 334 &&
    gameplay->tower_slots[1].free == true &&
    gameplay->coins >= gameplay->towers[gameplay->click_tower_type].cost) {
        gameplay->tower_slots[1].free = false;
        gameplay->tower_slots[1].sprite = gen_sprite_tower(gameplay,
        (sfVector2f){920, 166}, 1);
        gameplay->tower_slots[1].type = gameplay->click_tower_type;
        gameplay->coins -= gameplay->towers[gameplay->click_tower_type].cost;
    }
    put_towers_2(mouse, gameplay);
}