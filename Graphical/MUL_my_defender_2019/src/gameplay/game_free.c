/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_free.c
*/

#include "defense.h"

void free_towers(game_menu_t *gameplay)
{
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(gameplay->towers[i].texture);
        sfSprite_destroy(gameplay->towers[i].sprite);
    }
}

void game_free(game_menu_t *gameplay)
{
    while (gameplay->mobs)
        delete_sprite_list(&(gameplay->mobs), 0);
    sfClock_destroy(gameplay->mobs_clock);
    sfClock_destroy(gameplay->mobs_atk_clock);
    sfClock_destroy(gameplay->coins_clock);
    sfText_destroy(gameplay->wave_start->wave_text);
    sfClock_destroy(gameplay->wave_start->wave_print);
    sfTexture_destroy(gameplay->life_bar->texture);
    sfSprite_destroy(gameplay->life_bar->sprite);
    free_towers(gameplay);
    free(gameplay->wave_start);
    free(gameplay);
}