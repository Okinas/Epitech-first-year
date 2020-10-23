/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** check_around_towers.c
*/

#include "defense.h"

int get_abs(int nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}

void check_tower(int i, sprite_t tower, game_menu_t *gameplay)
{
    int mob_x = 0;
    int mob_y = 0;
    bool attacked = false;
    sfVector2f tower_pos = {0, 0};

    tower_pos = tower.pos;
    for (sprite_t *tmp = gameplay->mobs; tmp; tmp = tmp->next) {
        if (tmp->pos.x < 0)
            continue;
        mob_x = get_abs(tmp->pos.x - tower_pos.x + 39);
        mob_y = get_abs(tmp->pos.y - tower_pos.y + 70);
        if (mob_x + mob_y <= gameplay->towers[tower.type].range &&
        get_seconds(gameplay->tower_slots[i].timer_delay) >
        gameplay->towers[tower.type].speed_shot) {
            tmp->life -= gameplay->towers[tower.type].damage;
            sfClock_restart(gameplay->tower_slots[i].timer_delay);
            attacked = true;
        } if (attacked == true && tower.type != 3)
            break;
    }
}

void check_around_towers(game_menu_t *gameplay)
{
    sprite_t tower;

    for (int i = 0; i < 6; i++) {
        if (gameplay->tower_slots[i].free == true)
            continue;
        tower = gameplay->tower_slots[i];
        check_tower(i, tower, gameplay);
    }
}