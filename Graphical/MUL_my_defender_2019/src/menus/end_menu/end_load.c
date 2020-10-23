/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** end_load.c
*/

#include "defense.h"

end_menu_t *end_load(game_t *game)
{
    end_menu_t *end = malloc(sizeof(end_menu_t));

    end->total_coins = gen_txt((sfVector2f){100, 100},
    change_int_str(game->total_coins), "sprites/font.otf", 60);
    end->total_kill = gen_txt((sfVector2f){200, 100},
    change_int_str(game->total_mob), "sprites/font.otf", 60);
    return (end);
}