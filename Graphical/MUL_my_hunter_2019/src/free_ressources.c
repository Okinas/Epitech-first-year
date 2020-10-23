/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** free_ressources.c
*/

#include "hunter.h"

void destroy_texture(t_game_fox *main_game)
{
    sfTexture_destroy(main_game->sprites->texture);
    sfTexture_destroy(main_game->background->texture);
    sfTexture_destroy(main_game->menu->texture);
    sfTexture_destroy(main_game->pause->texture);
    sfTexture_destroy(main_game->dead->texture);
    sfTexture_destroy(main_game->end_game->texture);
    sfTexture_destroy(main_game->my_cursor->texture);
    sfSoundBuffer_destroy(main_game->gun_sound->buffer);
}

void destroy_sprite(sfRenderWindow *window, t_game_fox *main_game)
{
    sfRenderWindow_destroy(window);
    sfSound_destroy(main_game->gun_sound->sound);
    sfText_destroy(main_game->health_text);
    sfText_destroy(main_game->score_text);
    sfSprite_destroy(main_game->sprites->sprite);
    sfSprite_destroy(main_game->background->sprite);
    sfSprite_destroy(main_game->menu->sprite);
    sfSprite_destroy(main_game->dead->sprite);
    sfSprite_destroy(main_game->end_game->sprite);
    sfSprite_destroy(main_game->my_cursor->sprite);
    sfClock_destroy(main_game->my_game->clock);
}