/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** game_load.c
*/

#include "defense.h"

static void game_load_variables(game_menu_t *gameplay)
{
    gameplay->wave = 1;
    gameplay->end_wave = true;
    gameplay->mob_nbr = 5;
    gameplay->boss = false;
    gameplay->coins = 200;
    gameplay->life = 100;
    gameplay->mobs = NULL;
    gameplay->click_tower = false;
    gameplay->click_tower_type = 0;
    gameplay->mobs_clock = sfClock_create();
    gameplay->mobs_atk_clock = sfClock_create();
    gameplay->coins_clock = sfClock_create();
}

static void game_load_life_bar(game_menu_t *gameplay)
{
    sfIntRect rect = {964, 548, gameplay->life * 2.47, 47};

    gameplay->life_bar = gen_sprite((sfVector2f){928, 37}, rect,
    "sprites/sheet.png", (sfVector2f){1, 1});
}

static void game_load_tower_sprite(game_menu_t *gameplay, int i)
{
    if (i == 0) {
        gameplay->towers[i].rect = (sfIntRect){10, 22, 78, 147};
        gameplay->towers[i].range = 500;
        gameplay->towers[i].speed_shot = 2;
        gameplay->towers[i].damage = 100;
    } if (i == 1) {
        gameplay->towers[i].rect = (sfIntRect){97, 22, 78, 147};
        gameplay->towers[i].range = 270;
        gameplay->towers[i].speed_shot = 1;
        gameplay->towers[i].damage = 20;
    } if (i == 2) {
        gameplay->towers[i].rect = (sfIntRect){176, 22, 78, 147};
        gameplay->towers[i].range = 270;
        gameplay->towers[i].speed_shot = 3;
        gameplay->towers[i].damage = 50;
    } if (i == 3) {
        gameplay->towers[i].rect = (sfIntRect){257, 0, 63, 169};
        gameplay->towers[i].range = 350;
        gameplay->towers[i].speed_shot = 5;
        gameplay->towers[i].damage = 40;
    }
}

static void game_load_tower(game_menu_t *gameplay)
{
    char *path = "sprites/tower.png";

    for (int i = 0; i < 6; i++) {
        gameplay->tower_slots[i].free = true;
        gameplay->tower_slots[i].timer_delay = sfClock_create();
    }
    for (int i = 0; i < 4; i++) {
        gameplay->towers[i].sprite = sfSprite_create();
        gameplay->towers[i].texture = sfTexture_createFromFile(path, NULL);
        gameplay->towers[i].cost = 100 + (50 * i);
        game_load_tower_sprite(gameplay, i);
        sfSprite_setTexture(gameplay->towers[i].sprite,
        gameplay->towers[i].texture, sfFalse);
        sfSprite_setTextureRect(gameplay->towers[i].sprite,
        gameplay->towers[i].rect);
    }
}

game_menu_t *game_load(void)
{
    game_menu_t *gameplay = malloc(sizeof(game_menu_t));

    if (gameplay == NULL)
        return (NULL);
    gameplay->wave_start = malloc(sizeof(wave_t));
    game_load_variables(gameplay);
    create_sprite_list(&(gameplay->mobs), "mobs", gameplay->mob_nbr,
    (sfIntRect){3, 100, 43, 47});
    gameplay->wave_start->wave_text = gen_txt((sfVector2f){910, 490},
    my_strcat(my_strdup("Wave "), change_int_str(gameplay->wave)),
    "sprites/font.otf", 50);
    sfText_setOrigin(gameplay->wave_start->wave_text, (sfVector2f){50, 50});
    gameplay->wave_start->wave_print = sfClock_create();
    game_load_life_bar(gameplay);
    game_load_tower(gameplay);
    return (gameplay);
}