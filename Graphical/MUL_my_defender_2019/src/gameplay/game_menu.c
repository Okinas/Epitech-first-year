/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** game_loop.c
*/

#include "defense.h"

void attack_mobs(game_menu_t *gameplay, game_t *game)
{
    for (sprite_t *tmp = gameplay->mobs; tmp; tmp = tmp->next) {
        if (tmp->pos.x >= 1800 && get_seconds(gameplay->mobs_atk_clock) > 1.5)
            gameplay->life -= 1;
    }
    if (get_seconds(gameplay->mobs_atk_clock) > 1.5)
        sfClock_restart(gameplay->mobs_atk_clock);
    if (get_seconds(gameplay->coins_clock) > 3) {
        sfClock_restart(gameplay->coins_clock);
        gameplay->coins += 10;
        game->total_coins += 10;
    }
}

void anime_mobs(game_menu_t *gameplay, game_t *game)
{
    if (get_seconds(gameplay->mobs_clock) > 0.3) {
        for (sprite_t *tmp = gameplay->mobs; tmp; tmp = tmp->next) {
            if (tmp->rect.left == 97)
                tmp->rect.left = 3;
            else
                tmp->rect.left += 47;
            sfSprite_setTextureRect(tmp->sprite, tmp->rect);
        }
        sfClock_restart(gameplay->mobs_clock);
    }
}

void check_end_wave(game_menu_t *gameplay, game_t *game, int *status)
{
    if (gameplay->mob_nbr == 0)
        *status = 2;
}

void game_menu(sfRenderWindow *win, game_t *game, int *status)
{
    game_menu_t *gameplay = game_load();
    sfMusic *music = gen_music("sprites/game.ogg");

    if (game->loading == true)
        loading(win, status);
    if (game->music == true)
        sfMusic_play(music);
    while (*status == 1) {
        if (gameplay->end_wave == true)
            print_new_wave(win, gameplay, game);
        else {
            attack_mobs(gameplay, game);
            anime_mobs(gameplay, game);
            check_around_towers(gameplay);
            game_draw(game, gameplay, win);
            check_end_wave(gameplay, game, status);
        } game_events(win, status, gameplay, game);
    } if (game->music == true)
        sfMusic_pause(music);
    sfMusic_destroy(music);
    game_free(gameplay);
}