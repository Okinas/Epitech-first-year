/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_draw.c
*/

#include "defense.h"

static void draw_mobs(sfRenderWindow *win, game_menu_t *gameplay)
{
    int i = 0;

    for (sprite_t *tmp = gameplay->mobs; tmp; tmp = tmp->next) {
        sfRenderWindow_drawSprite(win, tmp->sprite, NULL);
        if (tmp->pos.x < 1800)
            tmp->pos.x += 1;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        if (tmp->life <= 0) {
            delete_sprite_list(&(gameplay->mobs), i);
            gameplay->mob_nbr -= 1;
        }
        i += 1;
    }
}

static void draw_gui(sfRenderWindow *win, game_menu_t *gameplay)
{
    sfText *wave = gen_txt((sfVector2f){1780, 30},
    change_int_str(gameplay->wave), "sprites/font.otf", 50);
    sfText *mob_left = gen_txt((sfVector2f){1555, 30},
    change_int_str(gameplay->mob_nbr), "sprites/font.otf", 50);
    sfText *coins = gen_txt((sfVector2f){1310, 30},
    change_int_str(gameplay->coins), "sprites/font.otf", 50);

    sfRenderWindow_drawText(win, wave, NULL);
    sfRenderWindow_drawText(win, mob_left, NULL);
    sfRenderWindow_drawText(win, coins, NULL);
    sfText_destroy(wave);
    sfText_destroy(mob_left);
    sfText_destroy(coins);
}

static void draw_lifebar(sfRenderWindow *win, game_menu_t *gameplay)
{
    sfIntRect rect = {964, 548, gameplay->life * 2.47, 47};

    gameplay->life_bar->rect = rect;
    sfSprite_setTextureRect(gameplay->life_bar->sprite,
    gameplay->life_bar->rect);
    sfRenderWindow_drawSprite(win, gameplay->life_bar->sprite, NULL);
}

static void draw_towers(sfRenderWindow *win, game_menu_t *gameplay)
{
    sfVector2i mouse_pos = {0, 0};

    for (int i = 0; i < 6; i++) {
        if (gameplay->tower_slots[i].free == false)
            sfRenderWindow_drawSprite(win, gameplay->tower_slots[i].sprite,
            NULL);
    }
    if (gameplay->click_tower == true) {
        mouse_pos = sfMouse_getPositionRenderWindow(win);
        sfSprite_setPosition(
        gameplay->towers[gameplay->click_tower_type].sprite,
        (sfVector2f){mouse_pos.x - 40, mouse_pos.y - 70});
        sfRenderWindow_drawSprite(win,
        gameplay->towers[gameplay->click_tower_type].sprite, NULL);
    }
}

void game_draw(game_t *game, game_menu_t *gameplay, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(win, game->gui->sprite, NULL);
    draw_mobs(win, gameplay);
    draw_gui(win, gameplay);
    draw_lifebar(win, gameplay);
    draw_towers(win, gameplay);
    sfRenderWindow_display(win);
}